/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2017  Thomas S. Anderson blobfish.at.gmx.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <QShowEvent>
#include <QHideEvent>
#include <QTimer>

#include "message/msgnode.h"
#include "message/msgsift.h"
#include "selection/slcmessage.h"
#include "selection/slceventhandler.h"
#include "dialogs/dlgselectionbutton.h"

using namespace dlg;

SelectionButton::SelectionButton(QWidget *parent) : SelectionButton(QString(), parent)
{
}

SelectionButton::SelectionButton(const QString &text, QWidget *parent) : SelectionButton(QIcon(), text, parent)
{
}

SelectionButton::SelectionButton(const QIcon &icon, const QString &text, QWidget *parent) : QPushButton(icon, text, parent)
{
  node = std::make_unique<msg::Node>();
  node->connect(msg::hub());
  sift = std::make_unique<msg::Sift>();
  sift->name = "dlg::SelectionButton";
  node->setHandler(std::bind(&msg::Sift::receive, sift.get(), std::placeholders::_1));
    
  setCheckable(true);
  mask = slc::None;
  
  setupDispatcher();
  
  connect(this, &QPushButton::toggled, this, &SelectionButton::toggledSlot);
}

SelectionButton::~SelectionButton()
{

}

void SelectionButton::setupDispatcher()
{
  sift->insert
  (
    {
      std::make_pair
      (
        msg::Response | msg::Post | msg::Selection | msg::Add
        , std::bind(&SelectionButton::selectionAdditionDispatched, this, std::placeholders::_1)
      )
      , std::make_pair
      (
        msg::Response | msg::Pre | msg::Selection | msg::Remove
        , std::bind(&SelectionButton::selectionSubtractionDispatched, this, std::placeholders::_1)
      )
      , std::make_pair
      (
        msg::Response | msg::Selection | msg::SetMask
        , std::bind(&SelectionButton::selectionMaskDispatched, this, std::placeholders::_1)
      )
    }
  );
}

/* I think it will be easier to check state in the message handlers than trying
 * to block boost signals in qt events. The selection list uses dirty to
 * keep in sync. So we have to call dirty before selectionAdded/removed
 * so any code assessing the list works
 */
void SelectionButton::selectionAdditionDispatched(const msg::Message &mIn)
{
  if (!isLive())
    return;
  
  slc::Message message = mIn.getSLC();
  message.accrue = accrueDefault;
  
  if (isSingleSelection)
  {
    QTimer::singleShot(0, this, SIGNAL(advance()));
    if (!messages.empty())
    {
      dirty();
      selectionRemoved(0);
    }
    messages.clear();
    messages.push_back(message);
    dirty();
    selectionAdded(0);
    node->sendBlocked(msg::Message(msg::Request | msg::Selection | msg::Clear));
    node->sendBlocked(msg::Message(msg::Request | msg::Selection | msg::Add, message));
  }
  else
  {
    messages.push_back(message);
    if (mIn.getSLC().accrue != message.accrue)
    {
      //we have changed the accrue so we have to re-sync the selection.
      node->sendBlocked(msg::Message(msg::Request | msg::Selection | msg::Clear));
      for (const auto &m : messages)
      {
        msg::Message mm(msg::Request | msg::Selection | msg::Add, m);
        node->sendBlocked(mm);
      }
    }
    dirty();
    selectionAdded(static_cast<int>(messages.size()) - 1);
  }
  
}

void SelectionButton::selectionSubtractionDispatched(const msg::Message &mIn)
{
  if (!isLive())
    return;
  
  const slc::Message& sm = mIn.getSLC();
  if (slc::has(messages, sm))
  {
    int index = slc::remove(messages, sm);
    selectionRemoved(index);
    dirty();
  }
}

void SelectionButton::setMessages(const slc::Messages &msIn)
{
  messages = msIn;
  dirty();
}

void SelectionButton::setMessages(const slc::Message &mIn)
{
  messages.clear();
  addMessage(mIn); //sends dirty signal
}

/*! @brief Set the selection of the button.
 * 
 * @parameter msIn are the new selection messages for the button.
 * @details This method does not emit the dirty signal. This
 * is beneficial for setting the initial state where we don't
 * want to trigger an update.
 */
void SelectionButton::setMessagesQuietly(const slc::Messages &msIn)
{
  messages = msIn;
}

/*! @brief Set the selection of the button.
 * 
 * @parameter mIn is the new selection message for the button.
 * @details This method does not emit the dirty signal. This
 * is beneficial for setting the initial state where we don't
 * want to trigger an update.
 */
void SelectionButton::setMessagesQuietly(const slc::Message &mIn)
{
  messages = slc::Messages(1, mIn);
}

void SelectionButton::addMessage(const slc::Message &mIn)
{
  slc::add(messages, mIn);
  dirty();
}

void SelectionButton::addMessages(const slc::Messages &msIn)
{
  std::copy(msIn.begin(), msIn.end(), std::back_inserter(messages));
  dirty();
}

void SelectionButton::removeMessage(int index)
{
  assert(index >= 0 && index < static_cast<int>(messages.size()));
  messages.erase(messages.begin() + index);
  dirty();
}

void SelectionButton::clear()
{
  messages.clear();
  dirty();
}

/*! @brief Add all stored to the selection system
 * 
 * @details This clears the current selection.
 */
void SelectionButton::syncToSelection()
{
  if (mask != slc::None)
    node->sendBlocked(msg::buildSelectionMask(mask));
  
  node->sendBlocked(msg::Message(msg::Request | msg::Selection | msg::Clear));
  
  for (const auto &m : messages)
  {
    msg::Message mm
    (
      msg::Request | msg::Selection | msg::Add
      , m
    );
    node->sendBlocked(mm);
  }
  
  if (!statusPrompt.isEmpty())
    node->sendBlocked(msg::buildStatusMessage(statusPrompt.toStdString()));
}

/*! @brief Add single stored item to the selection system
 * 
 * @details This does clear the current selection.
 */
void SelectionButton::highlightIndex(int index) const
{
  assert(static_cast<std::size_t>(index) < messages.size());
  
  node->sendBlocked(msg::Message(msg::Request | msg::Selection | msg::Clear));
  
  msg::Message mm(msg::Request | msg::Selection | msg::Add, messages.at(index));
  node->sendBlocked(mm);
}

void SelectionButton::setAccrue(int index, slc::Accrue accrue)
{
  assert(static_cast<std::size_t>(index) < messages.size());
  messages.at(index).accrue = accrue;
}

void SelectionButton::setAngle(int index, double angle)
{
  assert(static_cast<std::size_t>(index) < messages.size());
  messages.at(index).accrue.angle = angle;
}

bool SelectionButton::isLive()
{
  if (!isVisible() || !isChecked() || !isEnabled())
    return false;
  return true;
}

void SelectionButton::showEvent(QShowEvent *e)
{
  //here: isVisible() here = true. state already changed. calling parent just in case.
  QPushButton::showEvent(e);
  if (isLive())
    syncToSelection();
}

void SelectionButton::hideEvent(QHideEvent *e)
{
  //here: isVisible() here = false. state already changed. calling parent just in case.
  QPushButton::hideEvent(e);
  //isLive won't work here, because button is already hidden before hideEvent is called.
  if (isChecked() && isEnabled())
    node->sendBlocked(msg::Message(msg::Request | msg::Selection | msg::Clear));
}

void SelectionButton::changeEvent(QEvent *e)
{
  //same as above state already changed before this function gets called. calling parent just in case.
  QPushButton::changeEvent(e);
  if (e->type() != QEvent::EnabledChange)
    return;
  if (isLive())
    syncToSelection();
  else if (isChecked() && isVisible())
    node->sendBlocked(msg::Message(msg::Request | msg::Selection | msg::Clear));
}

void SelectionButton::toggledSlot(bool cState)
{
  //can't use isLive
  if (!isVisible() || !isEnabled())
    return;
  if (cState)
    syncToSelection();
  else
    node->sendBlocked(msg::Message(msg::Request | msg::Selection | msg::Clear));
}

void SelectionButton::selectionMaskDispatched(const msg::Message &messageIn)
{
  if (!isLive())
    return;
  
  mask = messageIn.getSLC().selectionMask;
}

/* -*-c++-*-
 * @file: fsm.cpp
 * @author: Dmitry Shpakov
 * @date: 2024/08/18
 * @licence: LGPL3 (see text at the end of a file)
 * @description: fsm class implementation
 */

#include <iostream>
#include <string>
#include "fsm.hpp"
#include "state.hpp"
#include "transition_table.hpp"

enum class Event;

Fsm::Fsm(State *initialState, const TransitionTable &table)
  : currentState(initialState), transitionTable(table) {
  if (currentState) {
    currentState->onEnter();
  }
}

void Fsm::triggerEvent(Event event) {
  State *nextState = transitionTable.getNextState(currentState, event);
  if (nextState) {
    if (currentState) {
      currentState->onExit();
    }
    currentState = nextState;
    if (currentState) {
      currentState->onEnter();
    }
  } else {
    if (currentState) {
      currentState->inState();
    } else {
      std::cout << "No transition available for event in the current state" << std::endl;
    }
  }
}

std::string Fsm::getCurrentStateName(void) const {
  return currentState ? currentState->name : "None";
}

/*

Copyright © 2024 Dmitry Shpakov

This library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published
by the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library; if not, see <http://www.gnu.org/licenses/>.

*/


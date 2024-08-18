/* -*-c++-*-
 * @file: transition_table.cpp
 * @author: Dmitry Shpakov
 * @date: 2024/08/18
 * @licence: LGPL3 (see text at the end of a file)
 * @description: transition table class implementation
 */

#include "state.hpp"
#include "transition_table.hpp"

enum class Event;

void TransitionTable::addTransition(State *fromState, Event event, State *toState) {
  transitions.emplace_back(fromState, event, toState);
}

State *TransitionTable::getNextState(State *currentState, Event event) const {
  for (const auto &transition : transitions) {
    if (transition.fromState == currentState && transition.event == event) {
      return transition.toState;
    }
  }
  return nullptr;
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


/* -*-c++-*-
 * @file: fsm.hpp
 * @author: Dmitry Shpakov
 * @date: 2024/08/18
 * @licence: LGPL3 (see text at the end of a file)
 * @description: fsm class definitions
 */

#pragma once

#include <string>
#include "state.hpp"
#include "transition_table.hpp"

enum class Event;

class Fsm {
public:
  Fsm(State *initialState, const TransitionTable &table);
  void triggerEvent(Event event);
  std::string getCurrentStateName(void) const;
private:
  State *currentState;
  const TransitionTable &transitionTable;
};

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


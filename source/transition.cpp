/* -*-c++-*-
 * @file: transition.cpp
 * @author: Dmitry Shpakov
 * @date: 2024/08/18
 * @licence: LGPL3 (see text at the end of a file)
 * @description: transition struct implementation
 */

#include "state.hpp"
#include "transition.hpp"

enum class Event;

Transition::Transition(State *fromState, Event event, State *toState) :
  fromState(fromState), event(event), toState(toState) {
    // empty
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


/* -*-c++-*-
 * @file: main.cpp
 * @author: Dmitry Shpakov
 * @date: 2024/08/18
 * @licence: LGPL3 (see text at the end of a file)
 * @description: example of usage of fsm
 */

#include <iostream>
#include <fsm.hpp>
#include "event.hpp"
#include "states.hpp"

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  IdleState idle;
  RunningState running;
  PausedState paused;

  TransitionTable table;
  table.addTransition(&idle,    Event::START,  &running);
  table.addTransition(&running, Event::PAUSE,  &paused);
  table.addTransition(&paused,  Event::RESUME, &running);
  table.addTransition(&idle,    Event::STOP,   &idle);

  Fsm fsm(&idle, table);
  
  std::cout << "Current state: " << fsm.getCurrentStateName() << std::endl;
  fsm.triggerEvent(Event::START);
  std::cout << "Current state: " << fsm.getCurrentStateName() << std::endl;
  fsm.triggerEvent(Event::PAUSE);
  std::cout << "Current state: " << fsm.getCurrentStateName() << std::endl;
  fsm.triggerEvent(Event::RESUME);
  std::cout << "Current state: " << fsm.getCurrentStateName() << std::endl;
  fsm.triggerEvent(Event::STOP);
  std::cout << "Current state: " << fsm.getCurrentStateName() << std::endl;
  fsm.triggerEvent(Event::PAUSE);
  std::cout << "Current state: " << fsm.getCurrentStateName() << std::endl;

  return 0;
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


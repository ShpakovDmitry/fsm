/* -*-c++-*-
 * @file: running_state.hpp
 * @author: Dmitry Shpakov
 * @date: 2024/08/18
 * @licence: LGPL3 (see text at the end of a file)
 * @description: running state class implementation
 */

#pragma once

#include <iostream>
#include "../source/state.hpp"

class RunningState : public State {
public:
  RunningState() : State("Running") { /* empty */}

  void onEnter(void) override {
    std::cout << "Entering Running State\n";
  }

  void inState(void) override {
    std::cout << "In Running State\n";
  }

  void onExit(void) override {
    std::cout << "Exiting Running State\n";
  }

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


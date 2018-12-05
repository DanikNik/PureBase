//
// Created by Иван Морозов on 02.12.2018.
//

#include "application.h"

void Application::setCommand(Command *command) {
  _commandQueue.push(command);
}

void Application::checkQueue() {
  while (!_commandQueue.empty()) {
    _commandQueue.front()->execute();
    _commandQueue.pop();
  }
}
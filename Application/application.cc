//
// Created by Иван Морозов on 02.12.2018.
//

#include "application.h"

void Application::setCommand(Command *command) {
  _commandQueue.push_back(command);
  checkQueue();
}

void Application::checkQueue() {
  for(int i = 0; i < _commandQueue.size(); ++i) {
    _commandQueue[i]->execute();
    _commandQueue.pop_back();
  }
}
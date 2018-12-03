//
// Created by Иван Морозов on 02.12.2018.
//

#ifndef PUREBASE_APPLICATION_H
#define PUREBASE_APPLICATION_H

#include "../Command/command.h"
#include <iostream>
#include <vector>
#include <thread>
#include <queue>

class Application {
 public:
  Application() = default;
  void setCommand(Command *command);
  void checkQueue();

 private:
  Command *_command;
  std::queue<Command*> _commandQueue;


};

#endif //PUREBASE_APPLICATION_H

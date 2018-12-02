//
// Created by Иван Морозов on 02.12.2018.
//

#ifndef PUREBASE_APPLICATION_H
#define PUREBASE_APPLICATION_H

#include "../Command/command.h"
#include <vector>
#include <thread>

class Application {
 public:
  Application() = default;
  void setCommand(Command *command);
  void checkQueue();

 private:
  Command *_command;
  std::vector<Command*> _commandQueue;


};

#endif //PUREBASE_APPLICATION_H

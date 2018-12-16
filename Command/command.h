//
// Created by Иван Морозов on 02.12.2018.
//

#ifndef PUREBASE_COMMAND_H
#define PUREBASE_COMMAND_H

class Command {
 public:
  virtual void execute() = 0;

 protected:
  Command() {}
};

#endif //PUREBASE_COMMAND_H

//
// Created by semyon on 16.11.18.
//

#ifndef PUREBASE_TEACHER_H
#define PUREBASE_TEACHER_H

#include "../Helper/helper.h"

class TeacherHelper : public Helper {
 public:
  void create(std::string);
  void changeName(std::string);
  std::vector<std::string> select(std::vector<std::string>);
  std::vector<std::string> selectByTag(std::vector<std::string>, std::string);
  void deleteRow(std::string);
  void showTables(std::string);
  void changeSpecialization(std::string);
};

#endif //PUREBASE_TEACHER_H

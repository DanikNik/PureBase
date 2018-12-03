//
// Created by semyon on 16.11.18.
//

#ifndef PUREBASE_LESSON_HELPER_H
#define PUREBASE_LESSON_HELPER_H

#include "../Helper/helper.h"
#include "../Adapter/adapter.h"

class LessonHelper : public Helper {
public:
    LessonHelper(std::string t_name) {
      _table_name = t_name;
      _db_name = "purebase";
      _db_type = "postgresql";
      _user_name = "semyon";
    }
    void create(std::string);
    void changeName(std::string) override;
    std::vector<std::string> select(std::vector<std::string>) override;
    std::vector<std::string> selectByTag(std::vector<std::string>, std::string) override;
    void deleteRow(std::string) override;
    void changeTeacher(std::string);
    void changeSubject(std::string);
    void changeTheme(std::string);
    void showTables(std::string) override;

 private:
  std::string _table_name;
  std::string _db_name;
  std::string _db_type;
  std::string _user_name;
};


#endif //PUREBASE_LESSON_HELPER_H

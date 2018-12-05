//
// Created by semyon on 16.11.18.
//

#ifndef PUREBASE_LESSON_HELPER_H
#define PUREBASE_LESSON_HELPER_H

#include "../Helper/helper.h"
#include "../Adapter/adapter.h"

class LessonHelper : public Helper {
public:
    void createTable(std::string);
    void changeName(std::string);
    std::vector<std::string> select(std::vector<std::string>);
    std::vector<std::string> selectByTag(std::vector<std::string>, std::string);
    void deleteRow(std::string);
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

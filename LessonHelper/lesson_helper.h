//
// Created by semyon on 16.11.18.
//

#ifndef PUREBASE_LESSON_HELPER_H
#define PUREBASE_LESSON_HELPER_H

#include "../Helper/helper.h"
#include "../Adapter/abstract_adapter.h"
#include <iostream>
#include <vector>
#include "../Adapter/PostgresAdapter/postgres_adapter.h"
#define LESSON "lesson"
#define TEACHER "teacher"


class LessonHelper : public Helper {
private:
    std::string lesson_name;
    std::string db_name;
    std::string table_name;
    std::string db_type;
    std::string user_name;
public:
    explicit LessonHelper(std::string);
    void Create(std::string) override;
    void ChangeName(std::string) override;
    std::vector<std::string> Select(std::vector<std::string>) override;
    std::vector<std::string> SelectByTag(std::vector<std::string>, std::string) override;
    void DeleteRow(std::string) override;
    void ChangeTeacher(std::string);
    void ChangeSubject(std::string);
    void ChangeTheme(std::string);
    void ShowTables() override;
};


#endif //PUREBASE_LESSON_HELPER_H

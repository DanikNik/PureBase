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
#include "../Lesson/lesson.h"
#define LESSON "lesson"
#define TEACHER "teacher"


class LessonHelper : public Helper {
private:
    Lesson* lesson;
public:
    explicit LessonHelper();
    explicit LessonHelper(std::string);
    explicit LessonHelper(int);
    int Create(std::string) override;
    void ChangeName(std::string) override;
    std::vector<std::string> Select(std::vector<std::string>) override;
    std::vector<std::string> SelectByTag(std::vector<std::string>, std::string) override;
    void DeleteRow() override;
    void ChangeTeacher(int);
    void ChangeSubject(int);
    void ChangeTheme(std::string);
    void ShowTables() override;
    ~LessonHelper();
};


#endif //PUREBASE_LESSON_HELPER_H

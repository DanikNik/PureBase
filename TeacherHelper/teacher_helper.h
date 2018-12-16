//
// Created by semyon on 16.11.18.
//

#ifndef PUREBASE_TEACHER_H
#define PUREBASE_TEACHER_H

#include "../Helper/helper.h"
#include "../Adapter/abstract_adapter.h"
#include <iostream>
#include <vector>
#include "../Adapter/PostgresAdapter/postgres_adapter.h"
#include "../Teacher/teacher.h"

class TeacherHelper : public Helper {
 private:
    Teacher *teacher;
 public:
    explicit TeacherHelper(std::string);
    explicit TeacherHelper();
    explicit TeacherHelper(int);
    ~TeacherHelper();
    int Create(std::string) override;
    void ChangeName(std::string) override;
    std::vector<std::string> Select(std::vector<std::string>) override;
    std::vector<std::string> SelectByTag(std::vector<std::string>, std::string) override;
    void DeleteRow() override;
    void ShowTables() override;
    void ChangeSpecialization(std::string);
};

#endif //PUREBASE_TEACHER_H

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
    int Create(std::vector<std::pair<std::string, std::string>> values) override;
    void ChangeName(std::string) override;
    void ChangeName(std::vector<std::pair<std::string, std::string>>, std::string);
    std::vector<std::string> Select(std::vector<std::string>) override;
    std::vector<std::vector<std::string>> Select(std::vector<std::string>,
                                    std::vector<std::pair<std::string, std::string>>) override;
    std::vector<std::string> SelectByTag(std::vector<std::string>, std::string) override;
    void DeleteRow() override;
    void DeleteRow(std::vector<std::pair<std::string, std::string>> options) override;
    void ShowTables() override;
    void ChangeSpecialization(std::string);
    void ChangeSpecialization(std::vector<std::pair<std::string, std::string>>, std::string);
    std::vector<std::vector<std::string>> GetAllRows();
};

#endif //PUREBASE_TEACHER_H

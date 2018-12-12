//
// Created by semyon on 16.11.18.
//

#ifndef PUREBASE_TEACHER_H
#define PUREBASE_TEACHER_H

#include "../Helper/helper.h"

class TeacherHelper : public Helper {
private:
    std::string teacher_name;
    std::string db_name;
    std::string table_name;
    std::string db_type;
    std::string user_name;
 public:
    explicit TeacherHelper(std::string);
    void Create(std::string) override;
    void ChangeName(std::string) override;
    std::vector<std::string> Select(std::vector<std::string>) override;
    std::vector<std::string> SelectByTag(std::vector<std::string>, std::string) override;
    void DeleteRow(std::string) override;
    void ShowTables() override;
    void ChangeSpecialization(std::string);
};

#endif //PUREBASE_TEACHER_H

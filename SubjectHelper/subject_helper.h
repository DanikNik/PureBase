//
// Created by semyon on 16.11.18.
//

#ifndef PUREBASE_SUBJECT_H
#define PUREBASE_SUBJECT_H

#include "../Helper/helper.h"

class SubjectHelper : public Helper {
private:
    std::string subject_name;
    std::string db_name;
    std::string table_name;
    std::string db_type;
    std::string user_name;
public:
    explicit SubjectHelper(std::string);
    void Create(std::string) override;
    void ChangeName(std::string) override;
    std::vector<std::string> Select(std::vector<std::string> param) override;
    std::vector<std::string> SelectByTag(std::vector<std::string> param, std::string tag) override;
    void DeleteRow(std::string name) override;
    void ChangeDescription(std::string);
    void ShowTables() override;
};


#endif //PUREBASE_SUBJECT_H

//
// Created by semyon on 16.11.18.
//

#ifndef PUREBASE_SUBJECT_H
#define PUREBASE_SUBJECT_H

#include "../Helper/helper.h"
#include "../Adapter/abstract_adapter.h"
#include <iostream>
#include <vector>
#include "../Adapter/PostgresAdapter/postgres_adapter.h"
#include "../Subject/subject.h"

class SubjectHelper : public Helper {
private:
    Subject *subject;
public:
    explicit SubjectHelper();
    explicit SubjectHelper(int);
    explicit SubjectHelper(std::string);
    ~SubjectHelper();
    int Create(std::string) override;
    int Create(std::vector<std::pair<std::string, std::string>> values) override;
    void ChangeName(std::string) override;
    void ChangeName(std::vector<std::pair<std::string, std::string>>, std::string);
    std::vector<std::string> Select(std::vector<std::string> param) override;
    std::vector<std::vector<std::string>> Select(std::vector<std::string>,
                                               std::vector<std::pair<std::string, std::string>>) override;
    std::vector<std::string> SelectByTag(std::vector<std::string> param, std::string tag) override;
    void DeleteRow() override;
    void DeleteRow(std::vector<std::pair<std::string, std::string>> options) override;
    void ChangeDescription(std::string);
    void ChangeDescription(std::vector<std::pair<std::string, std::string>>, std::string);
    void ShowTables() override;
};


#endif //PUREBASE_SUBJECT_H

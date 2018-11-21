//
// Created by semyon on 16.11.18.
//

#ifndef PUREBASE_SUBJECT_H
#define PUREBASE_SUBJECT_H

#include "../Helper/helper.h"

class SubjectHelper : public Helper {
public:
    void createTable(std::string);
    void changeName(std::string);
    std::vector<std::string> select(std::vector<std::string> param);
    std::vector<std::string> selectByTag(std::vector<std::string> param, std::string tag);
    void deleteRow(std::string name);
    void changeDescription(std::string);
    void showTables(std::string);
};


#endif //PUREBASE_SUBJECT_H

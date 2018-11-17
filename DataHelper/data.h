//
// Created by semyon on 16.11.18.
//

#ifndef PUREBASE_DATA_H
#define PUREBASE_DATA_H

#include "../Helper/helper.h"

class Data : public Helper {
public:
    virtual void createTable(std::string) = 0;
    virtual void changeName(std::string) = 0;
    virtual std::vector<std::string> select(std::vector<std::string> param) = 0;
    virtual std::vector<std::string> selectByTag(std::vector<std::string> param, std::string tag) = 0;
    virtual void deleteRow(std::string name) = 0;
    virtual void showTables(std::string) = 0;
    virtual void putFile(std::string) = 0;
};


#endif //PUREBASE_DATA_H

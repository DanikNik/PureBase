//
// Created by semyon on 16.11.18.
//

#ifndef PUREBASE_DATA_H
#define PUREBASE_DATA_H

#include "../Helper/helper.h"

class Data : public Helper {
public:
    void Create(std::string) override = 0;

    void ChangeName(std::string) override = 0;

    std::vector<std::string> Select(std::vector<std::string>) override = 0;

    std::vector<std::string> SelectByTag(std::vector<std::string>, std::string) override = 0;

    void DeleteRow(std::string) override = 0;

    void ShowTables() override = 0;
    virtual bool PutFile(std::string) = 0;
    virtual FILE GetFile(std::string) = 0;
};


#endif //PUREBASE_DATA_H

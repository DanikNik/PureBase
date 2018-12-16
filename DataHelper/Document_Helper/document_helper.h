//
// Created by semyon on 16.11.18.
//

#ifndef PUREBASE_DOCUMENT_HELPER_H
#define PUREBASE_DOCUMENT_HELPER_H

#include "../../Helper/helper.h"
#include "../../Adapter/abstract_adapter.h"
#include <iostream>
#include <vector>
#include "../../Adapter/PostgresAdapter/postgres_adapter.h"
#include "../data.h"
#include "../../Document/document.h"

class DocumentHelper : public Data {
private:
    Document *document;
public:
    explicit DocumentHelper();
    explicit DocumentHelper(int);
    explicit DocumentHelper(std::string);
    ~DocumentHelper();
    int Create(std::string) override;
    void ChangeName(std::string) override;
    std::vector<std::string> Select(std::vector<std::string>) override;
    std::vector<std::string> SelectByTag(std::vector<std::string>, std::string) override;
    void DeleteRow() override;
    void ShowTables() override;
    bool PutFile(std::string) override;
    FILE GetFile(std::string) override;
};


#endif //PUREBASE_DOCUMENT_HELPER_H

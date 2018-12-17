//
// Created by semyon on 16.11.18.
//

#ifndef PUREBASE_POSTGRES_ADAPTEE_H
#define PUREBASE_POSTGRES_ADAPTEE_H

#include <pqxx/pqxx>
#include <iostream>
#include "../abstract_adapter.h"


class PostgresAdapter: public AbstractAdapter {
private:
    pqxx::connection Connect;
public:
    //PostgresAdapter() = default;
    PostgresAdapter():Connect("dbname = purebase user = postgres"){};

    explicit PostgresAdapter(std::string options);
    ~PostgresAdapter() override {
        Connect.disconnect();
    }
    void disconnect(){
        Connect.disconnect();
    }
    bool CreateTable(std::string) override;
    bool Insert(std::string, std::vector<std::string>, std::vector<std::string>) override;
    bool Update(std::string,std::vector<std::pair<std::string,std::string>>, std::vector<std::pair<std::string,std::string>>) override;
    std::vector<std::vector<std::string>> Select(std::string, std::vector<std::string>, std::vector<std::pair<std::string,std::string>>) override;
    bool Delete(std::string, std::vector<std::pair<std::string,std::string>>) override;
    std::string GetMaximumID(std::string) override;
    std::vector<std::vector<std::string>> ShowTable(std::string) override;
};


#endif //PUREBASE_POSTGRES_ADAPTEE_H

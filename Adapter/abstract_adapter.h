//
// Created by semyon on 02.12.18.
//

#ifndef PUREBASE_ABSTRACT_ADAPTER_H
#define PUREBASE_ABSTRACT_ADAPTER_H

#include <vector>
#include <string>
#include <iostream>

class AbstractAdapter {
public:
    virtual ~AbstractAdapter() = 0;
    virtual bool CreateTable(std::string) = 0;
    virtual bool Insert(std::string, std::vector<std::string>,std::vector<std::string>) = 0;
    virtual bool Update(std::string,std::vector<std::pair<std::string,std::string>>, std::vector<std::pair<std::string,std::string>>) = 0;
    virtual std::vector<std::vector<std::string>> Select(std::string, std::vector<std::string>,std::vector<std::pair<std::string,std::string>>) = 0;
    virtual bool Delete(std::string, std::vector<std::pair<std::string,std::string>>) = 0;
    virtual std::vector<std::vector<std::string>> ShowTable(std::string) = 0;
    virtual std::string GetMaximumID(std::string) = 0;
};


#endif //PUREBASE_ABSTRACT_ADAPTER_H

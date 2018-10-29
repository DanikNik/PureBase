//
// Created by semyon on 29.10.18.
//

#ifndef PUREBASE_TABLESMANAGER_H
#define PUREBASE_TABLESMANAGER_H

#include <map>
#include "../table/table.h"

class TablesManager {
public:
    std::map<std::string,Table> tables;
    std::string tableCurrentName;
    Table* curTable = nullptr;

    TablesManager& operator=(const TablesManager& tablesManager);

    TablesManager();
    void printTables();
    void useTable(std::string tableName);
    void createTable();
    void readAllTables();
    void printCurrentTable();
    void insertRow();
    void saveTables();
    void selectWhere();
    void clearTable();
    void deleteRowsConditions();
    void clearColumnFromAllRows();
    void deleteTable(std::string tableName);
    void printColumns();
};

#endif //PUREBASE_TABLESMANAGER_H

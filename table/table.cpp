//
// Created by semyon on 29.10.18.
//

#include <iostream>
#include <fstream>
#include "TablesManager.h"

TablesManager::TablesManager() {
    curTable = nullptr;
}

TablesManager &TablesManager::operator=(const TablesManager &tablesManager) {
    this->tables = tablesManager.tables;
    this->tableCurrentName = tablesManager.tableCurrentName;
    return *this;
}

void TablesManager::printTables() {

}

void TablesManager::useTable(std::string tableName) {
}

void TablesManager::createTable() {
}

void TablesManager::readAllTables() {
}

void TablesManager::printCurrentTable() {
    if (curTable != nullptr) curTable->printTable();
}

void TablesManager::insertRow() {
    curTable->insertRow();
}

void TablesManager::saveTables() {
}

void TablesManager::selectWhere() {
    std::cout << "Enter name of Column: ";
    std::string column, value;
    std::cin >> column;
    std::cout << "Enter value:";
    std::cin >> value;

    curTable->printTable(curTable->getRowsWhere(column, value));
}

void TablesManager::clearTable() {
    curTable->deleteAllRows();
}

void TablesManager::deleteRowsConditions() {
    std::cout << "Enter column's name to delete records: ";
    std::string columnName, value;
    std::cin >> columnName;
    if (!curTable->isColumnExist(columnName)) {
        std::cout << "This column doesn't exist!" << std::endl;
        return;
    }
    std::cout << "Enter value to delete by: ";
    std::cin >> value;

    curTable->deleteByValue(columnName, value);
}

void TablesManager::clearColumnFromAllRows() {
    std::cout << "Enter name of Column to clear data: ";
    std::string columnName, fillingValue;
    std::cin >> columnName;
    if (!curTable->isColumnExist(columnName)) {
        std::cout << "This column doesn't exist!";
        return;
    }
    std::cout << "You may choose a value for filling or press enter for default values(Int=0,Double=0.0,String='',DBDate=0.0.0):";
    std::cin.ignore();
    getline(std::cin, fillingValue, '\n');
    curTable->clearColumns(columnName, fillingValue);
}

void TablesManager::deleteTable(std::string tableName) {
}

void TablesManager::printColumns() {
}

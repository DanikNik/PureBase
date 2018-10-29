//
// Created by semyon on 29.10.18.
//
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include "table.h"

Table::Table() {
    tableName = nullptr;
    primaryKey = nullptr;
}

Table::Table(std::string& name) { //Исправил передачу по значению на передачу по ссылке
    tableName = name;
}

void Table::readTable() {

}

void Table::getTableTittle(std::fstream &file) {

}

void Table::getHeaderInfo(std::fstream &file) {

}

void Table::getDataInfo(std::fstream &file) {

}

DBType Table::getType(std::string token) {
    if (token == "NoType") return DBType::NoType;
    else if (token == "Int") return DBType::Int;
    else if (token == "Double") return DBType::Double;
    else if (token == "String") return DBType::String;
    else return DBType(Date);
}

std::string Table::setType(DBType dbType){
    switch (dbType) {
        case DBType::String:
            return "String";
        case DBType::Int:
            return "Int";
        case DBType::Double:
            return "Double";
        case DBType::Date:
            return "Date";
    }
}


void* Table::setValueToVoid(std::string value, DBType dbType) {//необходимо добавить тип для даты
    switch (dbType) {
        case DBType::Int:
            return new int(stoi(value));
        case DBType::Double:
            return new double(stof(value));
        case DBType::String:
            return new std::string(value);
        default:
            return new std::string();
    }
}

void Table::printTable(std::vector<Row> table) {

}

void Table::printTable() {
    printTable(data);
}

void Table::insertRow() {

}

void Table::deleteRow(int index) {

}

void Table::writeDBTable() {

}

std::vector<Row> Table::getRowsWhere(std::string columnName, std::string value) {

}

void Table::deleteAllRows() {

}

void Table::clearColumns(std::string columnName, std::string fillingValues) {

}

void Table::deleteByValue(std::string columnName, std::string value) {

}

bool Table::isColumnExist(std::string columnName) {
    for (int i = 0; i < tableHeader.size(); ++i) {
        if (tableHeader[i].columnName == columnName) return true;
    }
    return false;
}

void Table::setTableName(const std::string &tableName) {
    Table::tableName = tableName;
}

void Table::setPrimaryKey(const std::string &primaryKey) {
    Table::primaryKey = primaryKey;
}

void Table::setTableHeader(const TableHeader &tableHeader) {
    Table::tableHeader = tableHeader;
}

std::string Table::getTableName() {
    return tableName;
}

TableHeader& Table::getHeader() {
    return tableHeader;
}
//
// Created by semyon on 29.10.18.
//

#ifndef PUREBASE_TABLE_H
#define PUREBASE_TABLE_H

#include <vector>
#include <string>
#include <fstream>

enum DBType {
    NoType,
    Int,
    Double,
    String,
    Date
};

struct Columns{
    std::string columnName;
    DBType colType;
};

typedef std::vector<void*> Row;
typedef std::vector<Columns> TableHeader;

class Table {
private:
    std::string tableName;
    std::string primaryKey;
    std::vector<Row> data;
    TableHeader tableHeader;
public:
    Table(std::string& name);
    Table();
    //Table(const Table& otherTable) = delete;
    //Table(Table&& otherTable) noexcept;

    //Table& operator=(const Table& otherTable) = delete;
    //Table& operator=(Table&& otherTable) noexcept;

    //~Table();

    std::string setType(DBType dbType);
    void setTableHeader(const TableHeader&);
    void setTable(const std::string&);
    void setTableName(const std::string &tableName);
    std::string getTableName();
    void setPrimaryKey(const std::string&);
    void readTable();
    void getHeaderInfo(std::fstream&);
    void getDataInfo(std::fstream&);
    void getTableTittle(std::fstream&);
    DBType getType(std::string);
    void* setValueToVoid(std::string,DBType);
    void printTable(std::vector<Row>);
    void printTable();
    void insertRow();
    void deleteRow(int);
    void writeDBTable();
    std::vector<Row> getRowsWhere(std::string,std::string);
    void deleteAllRows();
    void clearColumns(std::string,std::string);
    void deleteByValue(std::string,std::string);
    bool isColumnExist(std::string);
    std::string getTableName(std::string);
    TableHeader& getHeader();
};
#endif //PUREBASE_TABLE_H

//
// Created by semyon on 29.10.18.
//

#ifndef PUREBASE_DATABASE_MANAGER_H
#define PUREBASE_DATABASE_MANAGER_H

#include <string>
#include "../table/table.h"
#include "../TablesManager/tables_manager.h"

class DatabaseManager{
public:
    TablesManager tablesManager;
    static std::string currentDirectory;
    static  std::string defaultDirectory;

    void printDatabase();//??
    TablesManager* useDatabase(std::string dbName);
    void createDatabase(std::string basicString);
    void saveDatabase();
    void deleteDatabase(std::string basicString);

};


#endif //PUREBASE_DATABASE_MANAGER_H

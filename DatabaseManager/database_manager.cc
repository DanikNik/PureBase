//
// Created by semyon on 29.10.18.
//

#include <fstream>
#include <iostream>
#include <cstring>
#include "database_manager.h"
#include "../TablesManager/tables_manager.h"

std::string DatabaseManager::currentDirectory = "..\\PureBase\\";
std::string DatabaseManager::defaultDirectory = "..\\PureBase\\";


void DatabaseManager::printDatabase() {
}

TablesManager* DatabaseManager::useDatabase(std::string dbName) {
    return 0;
}

void DatabaseManager::createDatabase(std::string basicString) {

}

void DatabaseManager::saveDatabase() {
}

void DatabaseManager::deleteDatabase(std::string basicString) {

}
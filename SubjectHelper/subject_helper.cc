//
// Created by semyon on 16.11.18.
//

#include "subject_helper.h"
#include <iostream>

void SubjectHelper::createTable(std::string SubjectName) {
    std::cout<<"Document Helper worked..."<<std::endl;
}

void SubjectHelper::changeName(std::string SubjectName) {
    std::cout<<"Changed name..."<<std::endl;
}

void SubjectHelper::changeDescription(std::string Description) {
    std::cout<<"Changed name..."<<std::endl;
}

void SubjectHelper::deleteRow(std::string SubjectName) {
    std::cout<<"Row deleter..."<<std::endl;
}

void SubjectHelper::showTables(std::string TableName) {
    std::cout<<"Showing tables..."<<std::endl;
}

std::vector<std::string> SubjectHelper::select(std::vector<std::string> parametrs) {
    std::cout<<"selecting..."<<std::endl;
}

std::vector<std::string> SubjectHelper::selectByTag(std::vector<std::string> parametrs, std::string tag) {
    std::cout<<"selecting by tag...";
}
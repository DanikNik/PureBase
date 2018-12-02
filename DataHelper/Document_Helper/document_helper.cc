//
// Created by semyon on 16.11.18.
//

#include "document_helper.h"
#include <iostream>

void DocumentHelper::createTable(std::string documentName) {
    std::cout<<"Document Helper worked..."<<std::endl;
}

void DocumentHelper::changeName(std::string documentName) {
    std::cout<<"Changed name..."<<std::endl;
}

void DocumentHelper::deleteRow(std::string documentName) {
    std::cout<<"Row deleter..."<<std::endl;
}

void DocumentHelper::showTables(std::string documentName) {
    std::cout<<"Showing tables..."<<std::endl;
}

void DocumentHelper::putFiles(std::string filepath) {
    std::cout<<"Put file..."<<std::endl;
}

std::vector<std::string> DocumentHelper::select(std::vector<std::string> parametrs) {
    std::cout<<"selecting..."<<std::endl;
}

std::vector<std::string> DocumentHelper::selectByTag(std::vector<std::string> parametrs, std::string tag) {
    std::cout<<"selecting by tag...";
}
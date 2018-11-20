//
// Created by semyon on 16.11.18.
//

#include "video_helper.h"
#include <iostream>

void DocumentHelper::create(std::string videoName) {
    std::cout<<"Document Helper worked..."<<std::endl;
}

void DocumentHelper::changeName(std::string videoName) {
    std::cout<<"Changed name..."<<std::endl;
}

void DocumentHelper::deleteRow(std::string videoName) {
    std::cout<<"Row deleter..."<<std::endl;
}

void DocumentHelper::showTables(std::string TableName) {
    std::cout<<"Showing tables..."<<std::endl;
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
    std::cout<<"selecting by tag..."
}

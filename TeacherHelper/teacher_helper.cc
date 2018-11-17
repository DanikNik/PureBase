//
// Created by semyon on 16.11.18.
//

#include "teacher_helper.h"
#include <iostream>

void TeacherHelper::create(std::string TeacherName) {
    std::cout<<"Document Helper worked..."<<std::endl;
}

void TeacherHelper::changeName(std::string TeacherName) {
    std::cout<<"Changed name..."<<std::endl;
}

void TeacherHelper::changeSpecialization(std::string Description) {
    std::cout<<"Changed name..."<<std::endl;
}

void TeacherHelper::deleteRow(std::string TeacherName) {
    std::cout<<"Row deleter..."<<std::endl;
}

void TeacherHelper::showTables(std::string TableName) {
    std::cout<<"Showing tables..."<<std::endl;
}

std::vector<std::string> TeacherHelper::select(std::vector<std::string> parametrs) {
    std::cout<<"selecting..."<<std::endl;
}

std::vector<std::string> TeacherHelper::selectByTag(std::vector<std::string> parametrs, std::string tag) {
    std::cout<<"selecting by tag...";
}
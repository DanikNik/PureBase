//
// Created by semyon on 16.11.18.
//

#include "lesson_helper.h"
#include <iostream>

void LessonHelper::createTable(std::string LessonName) {
    std::cout<<"Document Helper worked..."<<std::endl;
}

void LessonHelper::changeName(std::string LessonName) {
    std::cout<<"Changed name..."<<std::endl;
}

void LessonHelper::changeTeacher(std::string TeacherName) {
    std::cout<<"Changed name..."<<std::endl;
}

void LessonHelper::changeSubject(std::string changeSubject) {
    std::cout<<"Changed name..."<<std::endl;
}

void LessonHelper::changeTheme(std::string theme) {
    std::cout<<"Changed name..."<<std::endl;
}

void LessonHelper::deleteRow(std::string LessonName) {
    std::cout<<"Row deleter..."<<std::endl;
}

void LessonHelper::showTables(std::string TableName) {
    std::cout<<"Showing tables..."<<std::endl;
}

std::vector<std::string> LessonHelper::select(std::vector<std::string> parametrs) {
    std::cout<<"selecting..."<<std::endl;
}

std::vector<std::string> LessonHelper::selectByTag(std::vector<std::string> parametrs, std::string tag) {
    std::cout<<"selecting by tag...";
}
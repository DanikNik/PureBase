#include <utility>

//
// Created by semyon on 16.11.18.
//

#include "teacher_helper.h"
#include <iostream>

TeacherHelper::TeacherHelper(std::string teacherName) {
    teacher_name = std::move(teacherName);
    db_name = "purebase";
    db_type = "postgresql";
    user_name = "semyon";
}

TeacherHelper::TeacherHelper() {
    db_name = "purebase";
    db_type = "postgresql";
    user_name = "semyon";
}

TeacherHelper::TeacherHelper(int teacher_id) {
    db_name = "purebase";
    db_type = "postgresql";
    user_name = "semyon";
}

int TeacherHelper::Create(std::string TeacherName) {
    std::cout<<"Document Helper worked..."<<std::endl;
    return 0;
}

void TeacherHelper::ChangeName(std::string TeacherName) {
    std::cout<<"Changed name..."<<std::endl;
}

void TeacherHelper::ChangeSpecialization(std::string Description) {
    std::cout<<"Changed name..."<<std::endl;
}

void TeacherHelper::DeleteRow() {
    std::cout<<"Row deleter..."<<std::endl;
}

void TeacherHelper::ShowTables() {
    std::cout<<"Showing tables..."<<std::endl;
}

std::vector<std::string> TeacherHelper::Select(std::vector<std::string> parametrs) {
    std::cout<<"selecting..."<<std::endl;
    return {"null"};
}

std::vector<std::string> TeacherHelper::SelectByTag(std::vector<std::string> parametrs, std::string tag) {
    std::cout<<"selecting by tag...";
    return {"null"};
}
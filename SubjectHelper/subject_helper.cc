#include <utility>

//
// Created by semyon on 16.11.18.
//

#include "subject_helper.h"
#include <iostream>

SubjectHelper::SubjectHelper(std::string subjectName) {
    subject_name = std::move(subjectName);
    db_name = "purebase";
    db_type = "postgresql";
    user_name = "semyon";
}

void SubjectHelper::Create(std::string SubjectName) {
    std::cout<<"Subject Helper creating..."<<std::endl;
}

void SubjectHelper::ChangeName(std::string SubjectName) {
    std::cout<<"Changed subject name..."<<std::endl;
}

void SubjectHelper::ChangeDescription(std::string Description) {
    std::cout<<"Changed subject description..."<<std::endl;
}

void SubjectHelper::DeleteRow(std::string SubjectName) {
    std::cout<<"Deletint subject..."<<std::endl;
}

void SubjectHelper::ShowTables() {
    std::cout<<"Showing subject table..."<<std::endl;
}

std::vector<std::string> SubjectHelper::Select(std::vector<std::string> parametrs) {
    std::cout<<"selecting subjects..."<<std::endl;
    return {"null"};
}

std::vector<std::string> SubjectHelper::SelectByTag(std::vector<std::string> parametrs, std::string tag) {
    std::cout<<"selecting subject by tag...";
    return {"null"};
}
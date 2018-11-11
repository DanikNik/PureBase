//
// Created by semyon on 11.11.18.
//

#include "teacher_helper.h"

bool TeacherHelper::createTeacher(Query query) {
    std::cout<<"Teacher creator worked...\n";
    return true;
}

bool TeacherHelper::updateTeacher(Query query) {
    std::cout<<"Teacher updater worked...\n";
    return true;
}

bool TeacherHelper::deleteTeacher(Query query) {
    std::cout<<"Teacher deleter worked...\n";
    return true;
}

std::vector<Query> TeacherHelper::SelectByTag(Query query,std::string Tag) {
    std::vector<Query> queryset;
    std::cout<<"Teacher tag selector worked...\n";
    return queryset;
}

std::vector<Query> TeacherHelper::Select(Query query) {
    std::vector<Query> queryset;
    std::cout<<"TeacherSelector worked...\n";
    return queryset;
}


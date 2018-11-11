//
// Created by semyon on 11.11.18.
//

#include "subject_helper.h"

bool SubjectHelper::createSubject(Query) {
    std::cout<<"Subject creator worked...\n";
    return true;
}

bool SubjectHelper::updateSubject(Query) {
    std::cout<<"Subject updater worked...\n";
    return true;
}

bool SubjectHelper::DeleteSubject(Query) {
    std::cout<<"Subject deleter worked...\n";
    return true;
}

std::vector<Query> SubjectHelper::SelectByTag(Query,std::string Tag) {
    std::vector<Query> queryset;
    std::cout<<"Subject tag selector worked...\n";
    return queryset;
}

std::vector<Query> SubjectHelper::Select(Query) {
    std::vector<Query> queryset;
    std::cout<<"Subject selector worked...\n";
    return queryset;
}

//
// Created by semyon on 11.11.18.
//

#include "lesson_helper.h"

bool LessonHelper::createLesson(Query) {
    std::cout<<"Lesson creator worked...\n";
    return true;
}

bool LessonHelper::updateLesson(Query) {
    std::cout<<"Lesson updater worked...\n";
    return true;
}

bool LessonHelper::DeleteLesson(Query) {
    std::cout<<"Lesson deleter worked...\n";
    return true;
}

std::vector<Query> LessonHelper::SelectByTag(Query,std::string Tag) {
    std::vector<Query> queryset;
    std::cout<<"Lesson tag selector worked...\n";
    return queryset;
}

std::vector<Query> LessonHelper::Select(Query) {
    std::vector<Query> queryset;
    std::cout<<"Lesson selector worked...\n";
    return queryset;
}



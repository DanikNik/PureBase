//
// Created by semyon on 11.11.18.
//

#ifndef PUREBASE_HEADER_H
#define PUREBASE_HEADER_H
#include "../Query/query.h"
#include "../TeacherHelper/teacher_helper.h"
#include "../SubjectHelper/subject_helper.h"
#include "../LessonHelper/lesson_helper.h"
#include "../DataHelper/data_helper.h"


class Header {
public:
    Query query;
    TeacherHelper teacher;
    LessonHelper lesson;
    SubjectHelper subject;
    DataHelper data;
};


#endif //PUREBASE_HEADER_H

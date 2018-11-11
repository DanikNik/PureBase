//
// Created by semyon on 11.11.18.
//

#ifndef PUREBASE_TEACHER_HELPER_H
#define PUREBASE_TEACHER_HELPER_H

#include "../Query/query.h"
#include <vector>
#include <iostream>
#include <string>

class TeacherHelper {
public:
    bool createTeacher(Query query);
    bool updateTeacher(Query query);
    std::vector<Query> SelectByTag(Query query,std::string Tag);
    std::vector<Query> Select(Query query);
    bool deleteTeacher(Query query);
};


#endif //PUREBASE_TEACHER_HELPER_H

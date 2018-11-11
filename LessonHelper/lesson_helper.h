//
// Created by semyon on 11.11.18.
//

#ifndef PUREBASE_LESSON_HELPER_H
#define PUREBASE_LESSON_HELPER_H


#include "../Query/query.h"
#include <vector>
#include <iostream>
#include <string>

class LessonHelper {
public:
    bool createLesson(Query query);
    bool updateLesson(Query query);
    std::vector<Query> SelectByTag(Query query,std::string Tag);
    std::vector<Query> Select(Query query);
    bool deleteLesson(Query query);
};



#endif //PUREBASE_LESSON_HELPER_H

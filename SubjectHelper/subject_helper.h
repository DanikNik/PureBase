//
// Created by semyon on 11.11.18.
//

#ifndef PUREBASE_SUBJECT_HELPER_H
#define PUREBASE_SUBJECT_HELPER_H


#include "../Query/query.h"
#include <vector>
#include <string>
#include <iostream>

class SubjectHelper {
public:
    SubjectHelper() = default;
    bool createSubject(Query);
    bool updateSubject(Query);
    std::vector<Query> SelectByTag(Query, std::string Tag);
    std::vector<Query> Select(Query);
    bool DeleteSubject(Query);
};



#endif //PUREBASE_SUBJECT_HELPER_H

//
// Created by semyon on 11.11.18.
//

#ifndef PUREBASE_DATA_HELPER_H
#define PUREBASE_DATA_HELPER_H

#include "../Query/query.h"
#include <vector>
#include <string>
#include <iostream>

class DataHelper {
public:
    DataHelper() = default;
    bool createData(Query);
    bool updateData(Query);
    std::vector<Query> SelectByTag(Query, std::string Tag);
    std::vector<Query> Select(Query);
    bool DeleteData(Query);
    void PutData(Query);
    void GetData(Query);
};


#endif //PUREBASE_DATA_HELPER_H

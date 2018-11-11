//
// Created by semyon on 11.11.18.
//

#include "data_helper.h"

bool DataHelper::createData(Query query) {
    std::cout<<"Data creator worked...\n";
    return true;
}

bool DataHelper::updateData(Query query) {
    std::cout<<"Data updater worked...\n";
    return true;
}

bool DataHelper::DeleteData(Query query) {
    std::cout<<"Data deleter worked...\n";
    return true;
}

std::vector<Query> DataHelper::SelectByTag(Query query,std::string Tag) {
    std::vector<Query> queryset;
    std::cout<<"Data tag selector worked...\n";
    return queryset;
}

std::vector<Query> DataHelper::Select(Query) {
    std::vector<Query> queryset;
    std::cout<<"Data selector worked...\n";
    return queryset;
}

void DataHelper::GetData(Query) {

}

void DataHelper::PutData(Query) {

}


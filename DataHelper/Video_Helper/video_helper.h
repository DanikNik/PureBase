//
// Created by semyon on 16.11.18.
//

#ifndef PUREBASE_VIDEO_HELPER_H
#define PUREBASE_VIDEO_HELPER_H

#include "../data.h"

class VideoHelper : public Data {
public:
    void create(std::string);
    void changeName(std::string);
    std::vector<std::string> select(std::vector<std::string>);
    std::vector<std::string> selectByTag(std::vector<std::string>, std::string);
    void deleteRow(std::string);
    void showTables(std::string);
    void putFiles(std::string);
};


#endif //PUREBASE_VIDEO_HELPER_H

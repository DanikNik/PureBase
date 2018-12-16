//
// Created by semyon on 16.12.18.
//

#ifndef PUREBASE_VIDEO_H
#define PUREBASE_VIDEO_H

#include "../Helper/defaults.h"
#include <string>
#include <map>

class Video {
private:
    std::string video_name;
    std::string db_name;
    std::string table_name;
    std::string db_type;
    std::string user_name;
    std::string video_id;
public:
    explicit Video();
    explicit Video(int);
    explicit Video(std::string);
    explicit Video(const Video&);
    explicit Video(Video&&);

    Video& operator=(const Video&);
    Video& operator=(Video&&);

    void SetId(int id);
    void SetVideoName(std::string);
    void SetDatabaseName(std::string);
    void SetUserName(std::string);
    void SetDatabaseType(std::string);
    std::map<std::string,std::string> GetParametrs();
};


#endif //PUREBASE_VIDEO_H

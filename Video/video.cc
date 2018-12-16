//
// Created by semyon on 16.12.18.
//

#include "video.h"

Video::Video() {
    video_id = DEFAULT_ID;
    video_name = DEFAULT_VIDEO_NAME;
    db_name = DEFAULT_DATABASE_NAME;
    db_type = DEFAULT_DATABASE_TYPE;
    table_name = DEFAULT_VIDEO_NAME;
    user_name = DEFAULT_USERNAME;
}

Video::Video(std::string videoName) {
    video_id = DEFAULT_ID;
    video_name = videoName;
    db_name = DEFAULT_DATABASE_NAME;
    db_type = DEFAULT_DATABASE_TYPE;
    table_name = DEFAULT_VIDEO_NAME;
    user_name = DEFAULT_USERNAME;
}

Video::Video(int videoID) {
    video_id = std::to_string(videoID);
    video_name = DEFAULT_VIDEO_NAME;
    db_name = DEFAULT_DATABASE_NAME;
    db_type = DEFAULT_DATABASE_TYPE;
    table_name = DEFAULT_VIDEO_NAME;
    user_name = DEFAULT_USERNAME;
}

Video::Video(const Video& other) {
    video_id = other.video_id;
    db_type = other.db_type;
    db_name = other.db_name;
    user_name = other.user_name;
    table_name = other.table_name;
    video_name = other.video_name;
}

Video::Video(Video&& other) {
    video_id = other.video_id;
    db_type = other.db_type;
    db_name = other.db_name;
    user_name = other.user_name;
    table_name = other.table_name;
    video_name = other.video_name;
    other.video_id = nullptr;
    other.db_name = nullptr;
    other.db_type = nullptr;
    other.video_name = nullptr;
    other.table_name = nullptr;
    other.user_name = nullptr;
}

Video& Video::operator=(const Video& other) {
    video_id = other.video_id;
    db_type = other.db_type;
    db_name = other.db_name;
    user_name = other.user_name;
    table_name = other.table_name;
    video_name = other.video_name;
    return *this;
}
Video& Video::operator=(Video&& other) {
    video_id = other.video_id;
    db_type = other.db_type;
    db_name = other.db_name;
    user_name = other.user_name;
    table_name = other.table_name;
    video_name = other.video_name;
    other.video_id = nullptr;
    other.db_name = nullptr;
    other.db_type = nullptr;
    other.video_name = nullptr;
    other.table_name = nullptr;
    other.user_name = nullptr;
    return *this;
}

void Video::SetId(int id) {
    video_id = std::to_string(id);
}

void Video::SetVideoName(std::string videoName) {
    video_name = videoName;
}

void Video::SetDatabaseName(std::string dbName) {
    db_name = dbName;
}

void Video::SetDatabaseType(std::string dbType) {
    db_type = dbType;
}

void Video::SetUserName(std::string userName) {
    user_name = userName;
}

std::map<std::string,std::string> Video::GetParametrs() {
    std::map<std::string,std::string> params;
    params["ID"] = video_id;
    params["Video"] = video_name;
    params["DB_NAME"] = db_name;
    params["DB_TYPE"] = db_type;
    params["TABLE_NAME"] = table_name;
    params["USER"] = user_name;
    return params;
}
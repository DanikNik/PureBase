//
// Created by semyon on 16.11.18.
//

#include "video_helper.h"
#include <iostream>

VideoHelper::VideoHelper() {
    video = new Video;
}

VideoHelper::VideoHelper(int docID) {
    video = new Video(docID);
}

VideoHelper::VideoHelper(std::string videoName) {
    video = new Video(videoName);
    auto id = Create(std::move(videoName));
    video->SetId(id);
}

int VideoHelper::Create(std::string videoName) {
    auto params = video->GetParametrs();
    std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
    AbstractAdapter* adapt;
    std::vector<std::string> columns = {"id", "name"};
    adapt = new PostgresAdapter();
    auto id = adapt->GetMaximumID(DEFAULT_VIDEO_NAME);

    std::vector<std::string> values  = {id, videoName};
    adapt->Insert(DEFAULT_VIDEO_NAME, columns, values);
    return atoi(id.c_str());
}

void VideoHelper::ChangeName(std::string videoName) {
    auto params = video->GetParametrs();
    std::string init_string = "dbname = " + params["DB_NAME"]  + " user = " + params["USER"];
    AbstractAdapter* adapt;
    adapt = new PostgresAdapter();
    auto option  = std::make_pair("name", videoName);
    std::vector<std::pair<std::string,std::string>> columns = { option };
    auto value  = std::make_pair("id",params["ID"]);
    std::vector<std::pair<std::string,std::string>> values = {value};
    adapt->Update(DEFAULT_VIDEO_NAME, columns, values);
}

void VideoHelper::DeleteRow() {
    auto params = video->GetParametrs();
    std::string init_string = "dbname = " + params["DB_NAME"]  + " user = " + params["USER"];
    AbstractAdapter* adapt;
    adapt = new PostgresAdapter();

    auto option = std::make_pair("id", params["ID"]);
    std::vector<std::pair<std::string,std::string>> options = {option};

    adapt->Delete(DEFAULT_VIDEO_NAME, options);
}

void VideoHelper::ShowTables() {
    auto params = video->GetParametrs();
    std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
    AbstractAdapter *adapt;
    adapt = new PostgresAdapter();
    auto result = adapt->ShowTable(DEFAULT_VIDEO_NAME);
    for(int i = 0; i!=result.size();i++){
        for(int j = 0; j!=result[i].size();j++)
            std::cout<<result[i][j]<<" ";
        std::cout<<std::endl;
    }
}

bool VideoHelper::PutFile(std::string filepath) {
    std::cout<<"Put document file..."<<std::endl;
}

std::vector<std::string> VideoHelper::Select(std::vector<std::string> parametrs) {
    auto params = video->GetParametrs();
    std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
    AbstractAdapter *adapt;
    adapt = new PostgresAdapter();
    auto idOption = std::make_pair("id", params["ID"]);
    std::vector<std::pair<std::string,std::string>> options = {idOption};
    auto result = adapt->Select(DEFAULT_VIDEO_NAME,parametrs,options);
    return result[0];
}

std::vector<std::string> VideoHelper::SelectByTag(std::vector<std::string> parametrs, std::string tag) {
    std::cout<<"selecting document by tag...";
    return {"null"};
}

FILE VideoHelper::GetFile(std::string){
    std::cout<<"get document file\n";
}

VideoHelper::~VideoHelper() {
    delete video;
}
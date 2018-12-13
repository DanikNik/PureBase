//
// Created by semyon on 16.11.18.
//

#include "video_helper.h"
#include <iostream>

VideoHelper::VideoHelper(std::string) {
    std::cout<<"Video Helper constructor worked..\n";
}

VideoHelper::VideoHelper() {
    std::cout<<"Video Helper constructor worked..\n";
}

VideoHelper::VideoHelper(int videoID) {
    std::cout<<"Video Helper constructor worked..\n";
}

int VideoHelper::Create(std::string videoName) {
    std::cout<<"Video Helper created..."<<std::endl;
    return 0;
}

void VideoHelper::ChangeName(std::string videoName) {
    std::cout<<"Changed name of Video..."<<std::endl;
}

void VideoHelper::DeleteRow() {
    std::cout<<"Deleting video..."<<std::endl;
}

void VideoHelper::ShowTables() {
    std::cout<<"Showing tables VIDEO..."<<std::endl;
}

bool VideoHelper::PutFile(std::string filepath) {
    std::cout<<"Put videofile..."<<std::endl;
}

std::vector<std::string> VideoHelper::Select(std::vector<std::string> parametrs) {
    std::cout<<"selecting video..."<<std::endl;
    return {"null"};
}

std::vector<std::string> VideoHelper::SelectByTag(std::vector<std::string> parametrs, std::string tag) {
    std::cout<<"selecting video by tag...";
    return {"null"};
}
FILE VideoHelper::GetFile(std::string){
    std::cout<<"get video file\n";
}
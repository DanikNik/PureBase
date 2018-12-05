//
// Created by semyon on 16.11.18.
//

#include "video_helper.h"
#include <iostream>

void VideoHelper::create(std::string videoName) {
    std::cout<<"Document Helper worked..."<<std::endl;
}

void VideoHelper::changeName(std::string videoName) {
    std::cout<<"Changed name..."<<std::endl;
}

void VideoHelper::deleteRow(std::string videoName) {
    std::cout<<"Row deleter..."<<std::endl;
}

void VideoHelper::showTables(std::string TableName) {
    std::cout<<"Showing tables..."<<std::endl;
}

void VideoHelper::putFiles(std::string filepath) {
    std::cout<<"Put file..."<<std::endl;
}

std::vector<std::string> VideoHelper::select(std::vector<std::string> parametrs) {
    std::cout<<"selecting..."<<std::endl;
}

std::vector<std::string> VideoHelper::selectByTag(std::vector<std::string> parametrs, std::string tag) {
    std::cout<<"selecting by tag...";
}

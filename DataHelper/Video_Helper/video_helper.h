//
// Created by semyon on 16.11.18.
//

#ifndef PUREBASE_VIDEO_HELPER_H
#define PUREBASE_VIDEO_HELPER_H

#include "../../Helper/helper.h"
#include "../../Adapter/abstract_adapter.h"
#include <iostream>
#include <vector>
#include "../../Adapter/PostgresAdapter/postgres_adapter.h"
#include "../data.h"
#include "../../Video/video.h"

class VideoHelper : public Data {
private:
    Video *video;
public:
    explicit VideoHelper();
    explicit VideoHelper(int);
    explicit VideoHelper(std::string);
    ~VideoHelper();
    int Create(std::string) override;
    int Create(std::vector<std::pair<std::string, std::string>> values) override;
    void ChangeName(std::string) override;
    void ChangeName(std::vector<std::pair<std::string, std::string>>, std::string);
    std::vector<std::string> Select(std::vector<std::string>) override;
    std::vector<std::vector<std::string>> Select(std::vector<std::string>,
                                               std::vector<std::pair<std::string, std::string>>) override;
    std::vector<std::string> SelectByTag(std::vector<std::string>, std::string) override;
    void DeleteRow() override;
    void DeleteRow(std::vector<std::pair<std::string, std::string>> options) override;
    void ShowTables() override;
    bool PutFile(std::string) override;
    FILE GetFile(std::string) override;
};


#endif //PUREBASE_VIDEO_HELPER_H

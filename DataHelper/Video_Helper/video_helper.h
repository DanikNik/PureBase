//
// Created by semyon on 16.11.18.
//

#ifndef PUREBASE_VIDEO_HELPER_H
#define PUREBASE_VIDEO_HELPER_H

#include "../data.h"

class VideoHelper : public Data {
private:
    std::string video_name;
    std::string db_name;
    std::string table_name;
    std::string db_type;
    std::string user_name;
    int data_id;
public:
    explicit VideoHelper();
    explicit VideoHelper(int);
    explicit VideoHelper(std::string);
    int Create(std::string) override;
    void ChangeName(std::string) override;
    std::vector<std::string> Select(std::vector<std::string>) override;
    std::vector<std::string> SelectByTag(std::vector<std::string>, std::string) override;
    void DeleteRow() override;
    void ShowTables() override;
    bool PutFile(std::string) override;
    FILE GetFile(std::string) override;
};


#endif //PUREBASE_VIDEO_HELPER_H

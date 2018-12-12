//
// Created by semyon on 16.11.18.
//

#include "lesson_helper.h"
#include <utility>

LessonHelper::LessonHelper(std::string l_name) {
    lesson_name = std::move(l_name);
    db_name = "purebase";
    db_type = "postgresql";
    user_name = "semyon";
}

void LessonHelper::Create(std::string LessonName) {
    std::string init_string = "dbname = " + db_name + " user = " + user_name;
    AbstractAdapter* adapt;
    std::vector<std::string> columns = {"id", "name"};
    adapt = new PostgresAdapter();
    std::string id = adapt->GetMaximumID("lesson");
    std::vector<std::string> values  = {id, LessonName};
    adapt->Insert("lesson", columns, values);
}

void LessonHelper::ChangeName(std::string LessonName) {
    std::string init_string = "dbname = " + db_name + " user = " + user_name;
    AbstractAdapter* adapt;
    adapt = new PostgresAdapter();
    auto option  = std::make_pair("name", LessonName);
    std::vector<std::pair<std::string,std::string>> columns = { option };
    auto value  = std::make_pair("name",lesson_name);
    std::vector<std::pair<std::string,std::string>> values = {value};
    adapt->Update("lesson", columns, values);
}

void LessonHelper::ChangeTeacher(std::string TeacherName) {
    std::string init_string = "dbname = " + db_name + " user = " + user_name;
    AbstractAdapter* adapt;
    adapt = new PostgresAdapter();

    std::vector<std::string> select_columns = {"id"};
    auto select_option = std::make_pair("name",TeacherName);
    std::vector<std::pair<std::string,std::string>> select_options = {select_option};
    std::vector<std::vector<std::string>> tab = adapt->Select("teacher", select_columns, select_options);
    int teacher_id;
    teacher_id = atoi(tab[0][0].c_str());
    std::cout<<teacher_id<<std::endl;

    auto option  = std::make_pair("teacher_id", tab[0][0]);
    std::vector<std::pair<std::string,std::string>> columns = { option };
    auto value  = std::make_pair("name",lesson_name);
    std::vector<std::pair<std::string,std::string>> values = {value};
    adapt->Update("lesson", columns, values);
}

void LessonHelper::ChangeSubject(std::string ChangedSubject) {
    std::string init_string = "dbname = " + db_name + " user = " + user_name;
    AbstractAdapter* adapt;
    adapt = new PostgresAdapter();

    std::vector<std::string> select_columns = {"id"};
    auto select_option = std::make_pair("name",ChangedSubject);
    std::vector<std::pair<std::string,std::string>> select_options = {select_option};
    std::vector<std::vector<std::string>> tab = adapt->Select("subject", select_columns, select_options);
    int teacher_id;
    teacher_id = atoi(tab[0][0].c_str());
    std::cout<<teacher_id<<std::endl;

    auto option  = std::make_pair("subject_id", tab[0][0]);
    std::vector<std::pair<std::string,std::string>> columns = { option };
    auto value  = std::make_pair("name",lesson_name);
    std::vector<std::pair<std::string,std::string>> values = {value};
    adapt->Update("lesson", columns, values);
}

void LessonHelper::ChangeTheme(std::string Theme) {
    std::string init_string = "dbname = " + db_name + " user = " + user_name;
    AbstractAdapter* adapt;
    adapt = new PostgresAdapter();

    auto option  = std::make_pair("theme", Theme);
    std::vector<std::pair<std::string,std::string>> columns = { option };
    auto value  = std::make_pair("name",lesson_name);
    std::vector<std::pair<std::string,std::string>> values = {value};
    adapt->Update("lesson", columns, values);
}

void LessonHelper::DeleteRow(std::string LessonID) {
    std::string init_string = "dbname = " + db_name + " user = " + user_name;
    AbstractAdapter* adapt;
    adapt = new PostgresAdapter();

    auto option  = std::make_pair("id", LessonID);
    std::vector<std::pair<std::string,std::string>> options = {option};

    adapt->Delete("lesson", options);
}

void LessonHelper::ShowTables() {
    std::cout<<"Showing tables..."<<std::endl;
}

std::vector<std::string> LessonHelper::Select(std::vector<std::string> parametrs) {
    std::cout<<"selecting..."<<std::endl;
    return {"null"};
}

std::vector<std::string> LessonHelper::SelectByTag(std::vector<std::string> parametrs, std::string tag) {
    std::cout<<"selecting by tag...";
    return {"null"};
}
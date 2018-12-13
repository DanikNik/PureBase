//
// Created by semyon on 13.12.18.
//

#include "lesson.h"

Lesson::Lesson() {
    lesson_id = DEFAULT_ID;
    lesson_name = DEFAULT_LESSON_NAME;
    db_name = DEFAULT_DATABASE_NAME;
    db_type = DEFAULT_DATABASE_TYPE;
    table_name = DEFAULT_LESSON_NAME;
    user_name = DEFAULT_USERNAME;
}

Lesson::Lesson(std::string lessonName) {
    lesson_id = DEFAULT_ID;
    lesson_name = lessonName;
    db_name = DEFAULT_DATABASE_NAME;
    db_type = DEFAULT_DATABASE_TYPE;
    table_name = DEFAULT_LESSON_NAME;
    user_name = DEFAULT_USERNAME;
}

Lesson::Lesson(int lessonID) {
    lesson_id = std::to_string(lessonID);
    lesson_name = DEFAULT_LESSON_NAME;
    db_name = DEFAULT_DATABASE_NAME;
    db_type = DEFAULT_DATABASE_TYPE;
    table_name = DEFAULT_LESSON_NAME;
    user_name = DEFAULT_USERNAME;
}
Lesson::Lesson(const Lesson& other) {
    lesson_id = other.lesson_id;
    db_type = other.db_type;
    db_name = other.db_name;
    user_name = other.user_name;
    table_name = other.table_name;
    lesson_name = other.lesson_name;
}

Lesson::Lesson(Lesson&& other) {
    lesson_id = other.lesson_id;
    db_type = other.db_type;
    db_name = other.db_name;
    user_name = other.user_name;
    table_name = other.table_name;
    lesson_name = other.lesson_name;
    other.lesson_id = nullptr;
    other.db_name = nullptr;
    other.db_type = nullptr;
    other.lesson_name = nullptr;
    other.table_name = nullptr;
    other.user_name = nullptr;
}

Lesson& Lesson::operator=(const Lesson& other) {
    lesson_id = other.lesson_id;
    db_type = other.db_type;
    db_name = other.db_name;
    user_name = other.user_name;
    table_name = other.table_name;
    lesson_name = other.lesson_name;
    return *this;
}
Lesson& Lesson::operator=(Lesson&& other) {
    lesson_id = other.lesson_id;
    db_type = other.db_type;
    db_name = other.db_name;
    user_name = other.user_name;
    table_name = other.table_name;
    lesson_name = other.lesson_name;
    other.lesson_id = nullptr;
    other.db_name = nullptr;
    other.db_type = nullptr;
    other.lesson_name = nullptr;
    other.table_name = nullptr;
    other.user_name = nullptr;
    return *this;
}


void Lesson::SetLessonName(std::string lessonName) {
    lesson_name = lessonName;
}

void Lesson::SetDatabaseName(std::string dbName) {
    db_name = dbName;
}

void Lesson::SetDatabaseType(std::string dbType) {
    db_type = dbType;
}

void Lesson::SetUserName(std::string userName) {
    user_name = userName;
}

std::map<std::string,std::string> Lesson::GetParametrs() {
    std::map<std::string,std::string> params;
    params["ID"] = lesson_id;
    params["LESSON"] = lesson_name;
    params["DB_NAME"] = db_name;
    params["DB_TYPE"] = db_type;
    params["TABLE_NAME"] = table_name;
    params["USER"] = user_name;
    return params;
}
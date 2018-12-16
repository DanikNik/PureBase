//
// Created by semyon on 16.12.18.
//

#include "teacher.h"

Teacher::Teacher() {
    teacher_id = DEFAULT_ID;
    teacher_name = DEFAULT_TEACHER_NAME;
    db_name = DEFAULT_DATABASE_NAME;
    db_type = DEFAULT_DATABASE_TYPE;
    table_name = DEFAULT_TEACHER_NAME;
    user_name = DEFAULT_USERNAME;
}

Teacher::Teacher(std::string teacherName) {
    teacher_id = DEFAULT_ID;
    teacher_name = teacherName;
    db_name = DEFAULT_DATABASE_NAME;
    db_type = DEFAULT_DATABASE_TYPE;
    table_name = DEFAULT_TEACHER_NAME;
    user_name = DEFAULT_USERNAME;
}

Teacher::Teacher(int teacherID) {
    teacher_id = std::to_string(teacherID);
    teacher_name = DEFAULT_TEACHER_NAME;
    db_name = DEFAULT_DATABASE_NAME;
    db_type = DEFAULT_DATABASE_TYPE;
    table_name = DEFAULT_TEACHER_NAME;
    user_name = DEFAULT_USERNAME;
}

Teacher::Teacher(const Teacher& other) {
    teacher_id = other.teacher_id;
    db_type = other.db_type;
    db_name = other.db_name;
    user_name = other.user_name;
    table_name = other.table_name;
    teacher_name = other.teacher_name;
}

Teacher::Teacher(Teacher&& other) {
    teacher_id = other.teacher_id;
    db_type = other.db_type;
    db_name = other.db_name;
    user_name = other.user_name;
    table_name = other.table_name;
    teacher_name = other.teacher_name;
    other.teacher_id = nullptr;
    other.db_name = nullptr;
    other.db_type = nullptr;
    other.teacher_name = nullptr;
    other.table_name = nullptr;
    other.user_name = nullptr;
}

Teacher& Teacher::operator=(const Teacher& other) {
    teacher_id = other.teacher_id;
    db_type = other.db_type;
    db_name = other.db_name;
    user_name = other.user_name;
    table_name = other.table_name;
    teacher_name = other.teacher_name;
    return *this;
}
Teacher& Teacher::operator=(Teacher&& other) {
    teacher_id = other.teacher_id;
    db_type = other.db_type;
    db_name = other.db_name;
    user_name = other.user_name;
    table_name = other.table_name;
    teacher_name = other.teacher_name;
    other.teacher_id = nullptr;
    other.db_name = nullptr;
    other.db_type = nullptr;
    other.teacher_name = nullptr;
    other.table_name = nullptr;
    other.user_name = nullptr;
    return *this;
}

void Teacher::SetId(int id) {
    teacher_id = std::to_string(id);
}

void Teacher::SetTeacherName(std::string teacherName) {
    teacher_name = teacherName;
}

void Teacher::SetDatabaseName(std::string dbName) {
    db_name = dbName;
}

void Teacher::SetDatabaseType(std::string dbType) {
    db_type = dbType;
}

void Teacher::SetUserName(std::string userName) {
    user_name = userName;
}

std::map<std::string,std::string> Teacher::GetParametrs() {
    std::map<std::string,std::string> params;
    params["ID"] = teacher_id;
    params["TEACHER"] = teacher_name;
    params["DB_NAME"] = db_name;
    params["DB_TYPE"] = db_type;
    params["TABLE_NAME"] = table_name;
    params["USER"] = user_name;
    return params;
}

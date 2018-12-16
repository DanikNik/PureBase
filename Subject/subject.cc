//
// Created by semyon on 16.12.18.
//

#include "subject.h"

Subject::Subject() {
    subject_id = DEFAULT_ID;
    subject_name = DEFAULT_SUBJECT_NAME;
    db_name = DEFAULT_DATABASE_NAME;
    db_type = DEFAULT_DATABASE_TYPE;
    subject_name = DEFAULT_SUBJECT_NAME;
    user_name = DEFAULT_USERNAME;
}

Subject::Subject(std::string subjectName) {
    subject_id = DEFAULT_ID;
    subject_name = subjectName;
    db_name = DEFAULT_DATABASE_NAME;
    db_type = DEFAULT_DATABASE_TYPE;
    table_name = DEFAULT_SUBJECT_NAME;
    user_name = DEFAULT_USERNAME;
}

Subject::Subject(int subjectID) {
    subject_id = std::to_string(subjectID);
    subject_name = DEFAULT_SUBJECT_NAME;
    db_name = DEFAULT_DATABASE_NAME;
    db_type = DEFAULT_DATABASE_TYPE;
    table_name = DEFAULT_SUBJECT_NAME;
    user_name = DEFAULT_USERNAME;
}

Subject::Subject(const Subject& other) {
    subject_id = other.subject_id;
    db_type = other.db_type;
    db_name = other.db_name;
    user_name = other.user_name;
    table_name = other.table_name;
    subject_name = other.subject_name;
}

Subject::Subject(Subject&& other) {
    subject_id = std::move(other.subject_id);
    db_type = std::move(other.db_type);
    db_name = std::move(other.db_name);
    user_name = std::move(other.user_name);
    table_name = std::move(other.table_name);
    subject_name = std::move(other.subject_name);
}

Subject& Subject::operator=(const Subject& other) {
    subject_id = std::move(other.subject_id);
    db_type = std::move(other.db_type);
    db_name = std::move(other.db_name);
    user_name = std::move(other.user_name);
    table_name = std::move(other.table_name);
    subject_name = std::move(other.subject_name);
    return *this;
}
Subject& Subject::operator=(Subject&& other) {
    subject_id = std::move(other.subject_id);
    db_type = std::move(other.db_type);
    db_name = std::move(other.db_name);
    user_name = std::move(other.user_name);
    table_name = std::move(other.table_name);
    subject_name = std::move(other.subject_name);
    return *this;
}

void Subject::SetId(int id) {
    subject_id = std::to_string(id);
}

void Subject::SetSubjectName(std::string subjectName) {
    subject_name = subjectName;
}

void Subject::SetDatabaseName(std::string dbName) {
    db_name = dbName;
}

void Subject::SetDatabaseType(std::string dbType) {
    db_type = dbType;
}

void Subject::SetUserName(std::string userName) {
    user_name = userName;
}

std::map<std::string,std::string> Subject::GetParametrs() {
    std::map<std::string,std::string> params;
    params["ID"] = subject_id;
    params["SUBJECT"] = subject_name;
    params["DB_NAME"] = db_name;
    params["DB_TYPE"] = db_type;
    params["TABLE_NAME"] = table_name;
    params["USER"] = user_name;
    return params;
}


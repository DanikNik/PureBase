//
// Created by semyon on 15.12.18.
//

#include "document.h"

Document::Document() {
    doc_id = DEFAULT_ID;
    doc_name = DEFAULT_DOCUMENT_NAME;
    db_name = DEFAULT_DATABASE_NAME;
    db_type = DEFAULT_DATABASE_TYPE;
    table_name = DEFAULT_DOCUMENT_NAME;
    user_name = DEFAULT_USERNAME;
}

Document::Document(std::string docName) {
    doc_id = DEFAULT_ID;
    doc_name = docName;
    db_name = DEFAULT_DATABASE_NAME;
    db_type = DEFAULT_DATABASE_TYPE;
    table_name = DEFAULT_DOCUMENT_NAME;
    user_name = DEFAULT_USERNAME;
}

Document::Document(int docID) {
    doc_id = std::to_string(docID);
    doc_name = DEFAULT_DOCUMENT_NAME;
    db_name = DEFAULT_DATABASE_NAME;
    db_type = DEFAULT_DATABASE_TYPE;
    table_name = DEFAULT_DOCUMENT_NAME;
    user_name = DEFAULT_USERNAME;
}

Document::Document(const Document& other) {
    doc_id = other.doc_id;
    db_type = other.db_type;
    db_name = other.db_name;
    user_name = other.user_name;
    table_name = other.table_name;
    doc_name = other.doc_name;
}

Document::Document(Document&& other) {
    doc_id = other.doc_id;
    db_type = other.db_type;
    db_name = other.db_name;
    user_name = other.user_name;
    table_name = other.table_name;
    doc_name = other.doc_name;
    other.doc_id = nullptr;
    other.db_name = nullptr;
    other.db_type = nullptr;
    other.doc_name = nullptr;
    other.table_name = nullptr;
    other.user_name = nullptr;
}

Document& Document::operator=(const Document& other) {
    doc_id = other.doc_id;
    db_type = other.db_type;
    db_name = other.db_name;
    user_name = other.user_name;
    table_name = other.table_name;
    doc_name = other.doc_name;
    return *this;
}
Document& Document::operator=(Document&& other) {
    doc_id = other.doc_id;
    db_type = other.db_type;
    db_name = other.db_name;
    user_name = other.user_name;
    table_name = other.table_name;
    doc_name = other.doc_name;
    other.doc_id = nullptr;
    other.db_name = nullptr;
    other.db_type = nullptr;
    other.doc_name = nullptr;
    other.table_name = nullptr;
    other.user_name = nullptr;
    return *this;
}

void Document::SetId(int id) {
    doc_id = std::to_string(id);
}

void Document::SetDocumentName(std::string docName) {
    doc_name = docName;
}

void Document::SetDatabaseName(std::string dbName) {
    db_name = dbName;
}

void Document::SetDatabaseType(std::string dbType) {
    db_type = dbType;
}

void Document::SetUserName(std::string userName) {
    user_name = userName;
}

std::map<std::string,std::string> Document::GetParametrs() {
    std::map<std::string,std::string> params;
    params["ID"] = doc_id;
    params["DOCUMENT"] = doc_name;
    params["DB_NAME"] = db_name;
    params["DB_TYPE"] = db_type;
    params["TABLE_NAME"] = table_name;
    params["USER"] = user_name;
    return params;
}
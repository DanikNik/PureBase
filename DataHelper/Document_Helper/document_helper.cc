#include <utility>

//
// Created by semyon on 16.11.18.
//

#include "document_helper.h"
#include <iostream>


DocumentHelper::DocumentHelper(std::string documentName) {
    document_name = std::move(documentName);
    db_name = "purebase";
    db_type = "postgresql";
    user_name = "semyon";
    table_name = "document";
}

DocumentHelper::DocumentHelper(int docID) {
    std::cout<<"doc creating..";
}
DocumentHelper::DocumentHelper() {
    std::cout<<"doc creating..";
}

int DocumentHelper::Create(std::string documentName) {
    std::cout<<"Document Helper creating..."<<std::endl;
    return 0;
}

void DocumentHelper::ChangeName(std::string documentName) {
    std::cout<<"Changed document name..."<<std::endl;

}

void DocumentHelper::DeleteRow() {
    std::cout<<"Deleting document..."<<std::endl;
}

void DocumentHelper::ShowTables() {
    std::cout<<"Showing document table..."<<std::endl;
}

bool DocumentHelper::PutFile(std::string filepath) {
    std::cout<<"Put document file..."<<std::endl;
}

std::vector<std::string> DocumentHelper::Select(std::vector<std::string> parametrs) {
    std::cout<<"selecting document..."<<std::endl;
    return {"null"};
}

std::vector<std::string> DocumentHelper::SelectByTag(std::vector<std::string> parametrs, std::string tag) {
    std::cout<<"selecting document by tag...";
    return {"null"};
}

FILE DocumentHelper::GetFile(std::string){
    std::cout<<"get document file\n";
}
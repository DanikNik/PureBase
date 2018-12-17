#include <utility>

//
// Created by semyon on 16.11.18.
//

#include "document_helper.h"
#include <iostream>

DocumentHelper::DocumentHelper() {
  document = new Document;
}

DocumentHelper::DocumentHelper(int docID) {
  document = new Document(docID);
}

DocumentHelper::DocumentHelper(std::string documentName) {
  document = new Document(documentName);
  auto id = Create(std::move(documentName));
  document->SetId(id);
}

int DocumentHelper::Create(std::string documentName) {
  auto params = document->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  std::vector<std::string> columns = {"id", "name"};
  adapt = new PostgresAdapter();
  auto id = adapt->GetMaximumID("document");

  std::vector<std::string> values = {id, documentName};
  adapt->Insert("document", columns, values);
  return atoi(id.c_str());
}

void DocumentHelper::ChangeName(std::string documentName) {
  auto params = document->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  auto option = std::make_pair("name", documentName);
  std::vector<std::pair<std::string, std::string>> columns = {option};
  auto value = std::make_pair("id", params["ID"]);
  std::vector<std::pair<std::string, std::string>> values = {value};
  adapt->Update("document", columns, values);
}

void DocumentHelper::DeleteRow() {
  auto params = document->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();

  auto option = std::make_pair("id", params["ID"]);
  std::vector<std::pair<std::string, std::string>> options = {option};

  adapt->Delete("document", options);
}

void DocumentHelper::ShowTables() {
  auto params = document->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  auto result = adapt->ShowTable("document");
  for (int i = 0; i != result.size(); i++) {
    for (int j = 0; j != result[i].size(); j++)
      std::cout << result[i][j] << " ";
    std::cout << std::endl;
  }
}

bool DocumentHelper::PutFile(std::string filepath) {
  std::cout << "Put document file..." << std::endl;
}

std::vector<std::string> DocumentHelper::Select(std::vector<std::string> parametrs) {
  auto params = document->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  auto idOption = std::make_pair("id", params["ID"]);
  std::vector<std::pair<std::string, std::string>> options = {idOption};
  auto result = adapt->Select(DEFAULT_DOCUMENT_NAME, parametrs, options);
  return result[0];
}

std::vector<std::vector<std::string>> DocumentHelper::Select(std::vector<std::string> parametrs,
                                                            std::vector<std::pair<std::string, std::string>> options) {
  auto params = document->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  auto result = adapt->Select(DEFAULT_DOCUMENT_NAME, parametrs, options);
  return result;
}

std::vector<std::string> DocumentHelper::SelectByTag(std::vector<std::string> parametrs, std::string tag) {
  std::cout << "selecting document by tag...";
  return {"null"};
}

FILE DocumentHelper::GetFile(std::string) {
  std::cout << "get document file\n";
}

DocumentHelper::~DocumentHelper() {
  delete document;
}

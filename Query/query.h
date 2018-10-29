//
// Created by daniknik on 29.10.18.
//

#ifndef PUREBASE_QUERY_H
#define PUREBASE_QUERY_H
#include <string>
#include <vector>
#include "DatabaseManager/DatabaseManager.h"


class Query {
 private:
  std::string query;
 public:
  Query();
  ~Query();
  virtual void Execute();
};

class CreateDBQuery : public Query {
 private:
  DataBaseManager* data_base_manager;
  std::string db_name;
 public:
  CreateDBQuery();
  ~CreateDBQuery()();
  void Execute() override;
};

class DeleteDBQuery : public Query {
 private:
  DataBaseManager* data_base_manager;
  std::string db_name;
 public:
  DeleteDBQuery();
  ~DeleteDBQuery()
  void Execute() override;
};

class CreateTableQuery : public Query {
 private:
  DataBaseManager* data_base_manager;
  std::string db_name;
  std::string table_name;
  std::vector<std::string> attributes;
 public:
  CreateTableQuery();
  ~CreateTableQuery();
  void Execute() override;
};

class DropTableQuery : public Query {
 private:
  DataBaseManager* data_base_manager;
  std::string db_name;
  std::string table_name;
 public:
  DropTableQuery();
  ~DropTableQuery();
  void Execute() override;
};

class UpdateTableQuery : public Query {
 private:
  DataBaseManager* data_base_manager;
  std::string db_name;
  std::string table_name;
  std::vector<std::string> values;
 public:
  UpdateTableQuery();
  ~UpdateTableQuery();
  void Execute() override;
};

class SelectTableQuery : public Query {
 private:
  DataBaseManager* data_base_manager;
  std::string db_name;
  std::string table_name;
  std::vector<std::string> selection_options;
 public:
  SelectTableQuery();
  ~SelectTableQuery();
  void Execute() override;
};

#endif //PUREBASE_QUERY_H

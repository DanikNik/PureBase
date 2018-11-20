#ifndef PUREBASE_QUERY_H
#define PUREBASE_QUERY_H
#include <string>
#include <vector>
#include "../DatabaseManager/database_manager.h"

//using namespace std;

class AbstractQuery {
 private:
  std::string query;
 public:
  AbstractQuery();
  ~AbstractQuery();
  virtual void Execute();
};

class CreateDBQuery : public AbstractQuery {
 private:
  DatabaseManager* data_base_manager;
  std::string db_name;
 public:
  CreateDBQuery();
  ~CreateDBQuery();
  void Execute() override;
};

class DeleteDBQuery : public AbstractQuery {
 private:
  DatabaseManager* data_base_manager;
  std::string db_name;
 public:
  DeleteDBQuery();
  ~DeleteDBQuery();
  void Execute() override;
};

class CreateTableQuery : public AbstractQuery {
 private:
  DatabaseManager* data_base_manager;
  std::string db_name;
  std::string table_name;
  std::vector<std::string> attributes;
 public:
  CreateTableQuery();
  ~CreateTableQuery();
  void Execute() override;
};

class DropTableQuery : public AbstractQuery {
 private:
  DatabaseManager* data_base_manager;
  std::string db_name;
  std::string table_name;
 public:
  DropTableQuery();
  ~DropTableQuery();
  void Execute() override;
};

class UpdateTableQuery : public AbstractQuery {
 private:
  DatabaseManager* data_base_manager;
  std::string db_name;
  std::string table_name;
  std::vector<std::string> values;
 public:
  UpdateTableQuery();
  ~UpdateTableQuery();
  void Execute() override;
};

class SelectTableQuery : public AbstractQuery {
 private:
  DatabaseManager* data_base_manager;
  std::string db_name;
  std::string table_name;
  std::vector<std::string> selection_options;
 public:
  SelectTableQuery();
  ~SelectTableQuery();
  void Execute() override;
};

// Пока заглушка
class Query {
public:
    Query() = default;
    void Execute();
};

#endif //PUREBASE_QUERY_H

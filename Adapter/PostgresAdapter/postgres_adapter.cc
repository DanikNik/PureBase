//
// Created by semyon on 16.11.18.
//

#include "postgres_adapter.h"
#include <typeinfo>
#include <pqxx/pqxx>

bool PostgresAdapter::Insert(std::string tablename, std::vector<std::string> columns, std::vector<std::string> values) {
  std::string query;
  pqxx::work wrk(Connect);
  query = "insert into " + tablename;
  query += "(";
  int i = 0;
  for (i = 0; i < columns.size(); i++) {
    query += columns[i];
    if (i < columns.size() - 1)
      query += ", ";
  }
  query += ") values (";
  for (i = 0; i < values.size(); i++) {
    query += wrk.quote(values[i]);
    if (i < values.size() - 1)
      query += ", ";
  }
  query += ");";
  std::cout << query << "\n";
  wrk.exec(query);
  wrk.commit();
}

std::vector<std::vector<std::string>> PostgresAdapter::ShowTable(std::string tableName) {
  std::string query;
  pqxx::work wrk(Connect);
  query = "select * from " + tableName + ";";
  auto res = wrk.exec(query);
  std::vector<std::vector<std::string>> response;
  for (int i = 0; i < res.size(); i++) {
    std::vector<std::string> str;
    for (int j = 0; j < res[i].size(); j++) {
      str.emplace_back(res[i][j].c_str());
    }
    response.push_back(str);
  }
  wrk.commit();
  return response;
}

std::vector<std::vector<std::string>> PostgresAdapter::Select(std::string tablename,
                                                              std::vector<std::string> columns,
                                                              std::vector<std::pair<std::string,
                                                                                    std::string>> options) {
  std::string query;
  pqxx::work wrk(Connect);
  query = "select ";
  int i = 0;
  for (i = 0; i < columns.size(); i++) {
    if (i == columns.size() - 1) {
      query += columns[i];
      break;
    }
    query += columns[i] + " , ";
  }
  query = query + " from " + tablename + " where ";
  for (i = 0; i < options.size(); i++) {
    if (i == options.size() - 1) {
      query += options[i].first + " = " + wrk.quote(options[i].second);
      break;
    }
    query += options[i].first + " = " + wrk.quote(options[i].second) + " , ";
  }
  query += ";";
  //std::cout << query << std::endl;
  std::vector<std::vector<std::string>> response;
  pqxx::result res = wrk.exec(query);
  //std::cout << res.size() << std::endl;
  for (i = 0; i < res.size(); i++) {
    std::vector<std::string> str;
    for (int j = 0; j < res[i].size(); j++) {
      str.emplace_back(res[i][j].c_str());
    }
    response.push_back(str);
  }
  wrk.commit();
  return response;
}

bool PostgresAdapter::CreateTable(std::string tableName) {
  return true;
}

bool PostgresAdapter::Update(std::string tablename,
                             std::vector<std::pair<std::string, std::string>> columns,
                             std::vector<std::pair<std::string, std::string>> options) {
  std::string query;
  pqxx::work wrk(Connect);
  query = "update ";
  query += tablename;
  query += " set ";
  int i = 0;
  for (i = 0; i < columns.size(); i++) {
    if (i == columns.size() - 1) {
      query += columns[i].first + " = " + wrk.quote(columns[i].second);
      break;
    }
    query += columns[i].first + " = " + wrk.quote(columns[i].second) + " , ";
  }
  query += " where ";
  for (i = 0; i < columns.size(); i++) {
    if (i == options.size() - 1) {
      query += options[i].first + " = " + wrk.quote(options[i].second);
      break;
    }
    query += options[i].first + " = " + wrk.quote(options[i].second) + " , ";
  }
  std::cout << query << std::endl;
  wrk.exec(query);
  wrk.commit();
  return true;
}

bool PostgresAdapter::Delete(std::string tablename, std::vector<std::pair<std::string, std::string>> options) {
  std::string query;
  pqxx::work wrk(Connect);
  int i = 0;
  query = "delete from ";
  query = query + tablename + " where ";
  for (i = 0; i < options.size(); i++) {
    if (i == options.size() - 1) {
      query += options[i].first + " = " + wrk.quote(options[i].second);
      break;
    }
    query += options[i].first + " = " + wrk.quote(options[i].second) + " , ";
  }
  wrk.exec(query);
  std::cout << query << std::endl;
  wrk.commit();

  return true;
}

std::string PostgresAdapter::GetMaximumID(std::string tablename) {
  std::string query;
  pqxx::work wrk(Connect);
  query = "select max(id) from " + tablename + ";";
  pqxx::result res = wrk.exec(query);
  int int_res;
  try {
    int_res = res[0][0].as<int>() + 1;
  } catch (std::exception e) {
    int_res = 0;
  }
  std::string rs = std::to_string(int_res);
  wrk.commit();
  return rs;
}

PostgresAdapter::PostgresAdapter(std::string options) {

}




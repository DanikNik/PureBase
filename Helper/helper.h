//
// Created by semyon on 16.11.18.
//

#ifndef PUREBASE_HELPER_H
#define PUREBASE_HELPER_H

#include <iostream>
#include <string>
#include <vector>

class Helper {
 public:
  virtual int Create(std::string) = 0;
  virtual void ChangeName(std::string) = 0;
  virtual std::vector<std::string> Select(std::vector<std::string> param) = 0;
  virtual std::vector<std::vector<std::string>> Select(std::vector<std::string>,
                                          std::vector<std::pair<std::string, std::string>>) = 0;
  virtual std::vector<std::string> SelectByTag(std::vector<std::string> param, std::string tag) = 0;
  virtual void DeleteRow() = 0;
  virtual void ShowTables() = 0;
};

#endif //PUREBASE_HELPER_H

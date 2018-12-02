//
// Created by daniknik on 02.12.18.
//

#ifndef PUREBASE_PARSER_H
#define PUREBASE_PARSER_H
#include "../Helper/helper.h"

using namespace std;

class Parser {
 public:
  Parser() = default;
  ~Parser() = default;
  Helper* query(const std::string &query);
};

#endif //PUREBASE_PARSER_H

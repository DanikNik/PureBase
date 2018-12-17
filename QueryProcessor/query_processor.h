//
// Created by daniknik on 02.12.18.
//

#ifndef PUREBASE_PARSER_H
#define PUREBASE_PARSER_H


//move includes to cpp file
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <set>
#include <exception>
#include <iostream>
#include "../Helper/helper.h"
#include "../Command/command.h"

#include "../session/session.h"
#include "../session_director/session_director.h"

#include "../DataHelper/Video_Helper/video_helper.h"
#include "../DataHelper/Document_Helper/document_helper.h"
#include "../LessonHelper/lesson_helper.h"
#include "../SubjectHelper/subject_helper.h"
#include "../TeacherHelper/teacher_helper.h"

#include "../CreateDBCommand/create_db_command.h"
#include "../CreateTableCommand/create_table_command.h"
#include "../DeleteDBCommand/delete_db_command.h"
#include "../DropTableCommand/drop_table_command.h"
#include "../SelectTableCommand/select_table_command.h"

namespace pt = boost::property_tree;

class QueryProcessor {
 private:
  Sys *system_table = Sys::get_instance();
 public:
  QueryProcessor() = default;
  ~QueryProcessor() = default;
  Command *ProcessJSONToCommand(std::string query);
  //умные указатели
};

class NothingCommand : public Command {
 public:
  NothingCommand() = default;
  explicit NothingCommand(std::string anything,
                          std::vector<std::pair<std::string, std::string>> _attributes) : payload(anything),
                                                                                          attributes(_attributes) {}
  void execute() { std::cout << payload << std::endl; };
 private:
  std::string payload;
  std::vector<std::pair<std::string, std::string>> attributes;
};

#endif //PUREBASE_PARSER_H

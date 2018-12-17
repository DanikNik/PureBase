//
// Created by daniknik on 02.12.18.
//

#include "query_processor.h"
//TODO заменить все типы на boost optional

Command *QueryProcessor::ProcessJSONToCommand(std::string query, std::shared_ptr<Socket> client) {
  try {

    Permissions permissions;
    permissions.set_write();
    permissions.set_read();

    // Создали пользователя в системной таблице
    Sys *system_table = Sys::get_instance();
    system_table->add_user("abcd", "Ivan", permissions);

    // Создаем сессию с пользователем
    SessionType type = SBN;
    std::string token = "abcd";
    SessionByName sba_session;
    SessionDirector director(&sba_session);
    director.create_session(token, type);
    auto ses = sba_session.get_result();

    std::stringstream json_code(query);
    pt::ptree tree;
    pt::read_json(json_code, tree);
    auto user_token = tree.get<std::string>("user");
//    std::cout << user_token << std::endl;
    auto method = tree.get<std::string>("action.method");
//    std::cout << method << std::endl;
    auto model = tree.get<std::string>("action.model");
//    std::cout << model << std::endl;
    std::vector<std::pair<std::string, std::string>> attributes;
    std::vector<std::string> params;
//    std::cout << system_table->get_user_name(user_token) << std::endl;

    BOOST_FOREACH(pt::ptree::value_type &attrib, tree.get_child("action.attribs")) {
//            std::cout << attrib.second.data() << std::endl;
            attributes.push_back(std::make_pair(std::string(attrib.first), std::string(attrib.second.data())));
            params.emplace_back(std::string(attrib.first));
//            std::cout << attrib.first << ":" << attrib.second.data() << std::endl;
          }

//handle can-handle
    Helper *helper;
    if (model == "teacher") {
      helper = new TeacherHelper();
    } else if (model == "lesson") {
      helper = new LessonHelper();
    } else if (model == "subject") {
      helper = new SubjectHelper();
    }

    if (method == "CREATE") {
      return new CreateTableCommand(&sba_session,
                                    helper,
                                    model,
                                    "purebase",
                                    attributes);
    } else if (method == "SELECT") {
      return new SelectTableCommand(&sba_session,
                                    helper,
                                    client,
                                    "teacher",
                                    "purebase",
                                    params,
//                                    {"id", "name", "specialization"},
                                    attributes);
//    } else if (method == "DELETE") {
//      return nullptr;
    } else {
      return nullptr;
    }

//    return new NothingCommand(user_token, attributes);
  }
  catch (pt::json_parser_error &e) {
    std::cerr << e.what() << std::endl;
    std::cerr << "PROPERTY TREE FAILURE" << std::endl;
    return nullptr;
  }
}
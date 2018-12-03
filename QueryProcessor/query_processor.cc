//
// Created by daniknik on 02.12.18.
//

#include "query_processor.h"


Command* QueryProcessor::ProcessJSONToCommand(std::string query) {
  try {
    std::stringstream json_code(query);
    pt::ptree tree;
    pt::read_json(json_code, tree);
    auto user_token = tree.get<std::string>("user");
    auto actions_method = tree.get<std::string>("action.method");
    std::vector<std::pair<std::string, std::string>> attributes;
    std::cout << system_table->get_user_name(user_token) << std::endl;

    BOOST_FOREACH(pt::ptree::value_type &attrib, tree.get_child("action.attribs")) {
            std::cout << attrib.second.data() << std::endl;
            attributes.emplace_back(attrib.first, attrib.second.data());
    }

    return new NothingCommand(user_token, attributes);
  }
  catch(pt::json_parser_error &e){
    std::cerr << e.what() << std::endl;
    std::cerr << "PROPERTY TREE PIZDEC" << std::endl;
    return nullptr;
  }
}
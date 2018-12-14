//
// Created by daniknik on 03.12.18.
//

#include <cstdlib>
#include "simple_cmd_client.h"
void Client::start() {
  process_command();
}

int Client::send_file(std::string path) {
  try {
    std::ifstream fin(path);
    if (fin.is_open()) {
      std::stringstream ss;
      ss << fin.rdbuf();

      socket.send(ss.str());
      std::cout << socket.recv() << std::endl;
      fin.close();
    } else {
      std::cerr << "[!]no such file\n";
      return -1;
    }
  }
  catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
void Client::process_command() {
  std::string command;
  while (true) {
    std::cout << "> ";
    std::cin >> command;
    try {
      if (command == "/connect") {
        std::cin >> _host >> _port;
        socket.close();
        socket.connect(_host, _port);
      } else if (command == "/disconnect") {
        socket.close();
      } else if (command == "/sendfile") {
        std::string path;
        std::cin >> path;
        send_file(path);
      } else if (command == "/exit") {
        socket.close();
        exit(0);
      }
      else {
        std::cout << "NO SUCH COMMAND\n";
      }
    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
}

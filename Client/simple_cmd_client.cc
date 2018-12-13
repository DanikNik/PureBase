//
// Created by daniknik on 03.12.18.
//

#include "simple_cmd_client.h"
void Client::start() {
  process_command();
}
int Client::work() {
  try {
    Socket socket;
    socket.connect(_host, _port);
    while (true) {
      std::cout << std::endl;
      std::cout << "[+]Enter path to the json file with transaction\n> ";
      std::string path;
      std::cin >> path;
      std::ifstream fin(path);
      if (fin.is_open()) {
        std::stringstream ss;
        ss << fin.rdbuf();

        socket.send(ss.str());
        std::cout << socket.recv() << std::endl;
      } else {
        std::cerr << "[!]no such file\n";
      }
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
    std::cin >> command;
    if (command == "/connect") {
      std::cin >> _host >> _port;
      work();
    } else {
      std::cout << "NO SUCH COMMAND\n";
    }
  }
}

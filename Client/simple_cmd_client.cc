//
// Created by daniknik on 03.12.18.
//

#include <cstdlib>
#include "simple_cmd_client.h"
void Client::start() {
  try {
    while (true) {
      process_command();
    }
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return;
  }
}

void Client::process_command() {
  std::string command;
  std::cout << "> ";
  std::cin >> command;
  try {
    if (command == "/connect") {
      connect();
    } else if (command == "/disconnect") {
      disconnect();
    } else if (command == "/transaction") {
      transaction();
    } else if (command == "/exit") {
      exit_client();
    } else {
      std::cout << "NO SUCH COMMAND\n";
    }
  } catch (std::exception &e) {
    std::cerr << "CLIENT::PROCESS_COMMAND ERROR\n";
    std::cerr << e.what() << std::endl;
  }
}
void Client::handshake(CONNECTION_SIGNALS signal) {
  try {
    auto req = (CONNECTION_SIGNALS) stoi(socket.recv());
    switch (req) {
      case REQUEST_HEADERS:socket.send(std::to_string(signal));
        break;
      default:
//        love you. tupoy mudak
        std::cout << "HANDSHAKE ERROR" << std::endl;
        break;
    }
  } catch (std::exception &e) {
    std::cerr << "CLIENT::HANDSHAKE ERROR\n";
    std::cerr << e.what() << std::endl;
  }

}
int Client::send_transaction(std::string path) {
  try {
    std::ifstream fin(path);
    if (fin.is_open()) {
      std::stringstream ss;
      ss << fin.rdbuf();
      fin.close();
      socket.send(ss.str());
      std::cout << socket.recv() << std::endl;
    } else {
      std::cerr << "[!]no such file\n";
      return -1;
    }
  } catch (std::exception &e) {
    std::cerr << "CLIENT::SEND_TRANSACTION ERROR\n";
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
void Client::connect() {
//  std::cin >> _host >> _port;
  if (connected) {
    handshake(DISCONNECT);
    socket.close();
  }
  socket.connect(_host, _port);
  handshake(CONNECT);
  connected = true;
}
void Client::disconnect() {
  if (connected) {
    std::string path;
    std::cin >> path;
    handshake(TRANSACTION);
    send_transaction(path);
  } else {
    std::cout << "YOU ARE NOT CONNECTED\n";
  }
}
void Client::transaction() {
  if (connected) {
    std::string path;
    std::cin >> path;
    handshake(TRANSACTION);
    send_transaction(path);
  } else {
    std::cout << "YOU ARE NOT CONNECTED\n";
  }
}
void Client::exit_client() {
  if (connected) {
    handshake(DISCONNECT);
    socket.close();
    connected = false;
    exit(0);
  } else {
    exit(0);
  }
}

//int Client::send_file(std::string path) {
//  try{
//    std::ifstream fin(path, std::ios::binary);
//    if(fin.is_open()){
//      std::stringstream ss;
//      ss << fin.rdbuf();
//      fin.close();
//      socket.send(ss.str());
//      std::cout << socket.recv() << std::endl;
//    } else {
//      std::cerr << "[!] no such file\n";
//      return -1;
//    }
//  } catch (std::exception& e){
//    std::cerr << e.what() << std::endl;
//  }
//  return 0;
//}

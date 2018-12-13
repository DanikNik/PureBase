//
// Created by daniknik on 03.12.18.
//

#include "simple_cmd_client.h"
void Client::start() {
  work();
}
int Client::work() {
  std::string path;
  std::cin >> path;
  std::ifstream fin(path);
  std::stringstream ss;
  ss << fin.rdbuf();

  Socket socket;
  socket.connect(host, port);
  socket.send(ss.str());
  std::cout << socket.recv() << std::endl;

  return 0;
}

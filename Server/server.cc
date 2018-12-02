//
// Created by daniknik on 02.12.18.
//

#include "server.h"
#include "../CreateDBCommand/create_db_command.h"

void Server::start() {
  try {
    Socket s;
    s.createServerSocket(port, 25);

    pid_t pid = fork();
    if (pid > 0) {
      std::cerr << "parent: " << getpid() << std::endl;
    } else {
      std::cerr << "child: " << getpid() << std::endl;
    }

    while (true) {
      std::shared_ptr<Socket> client = s.accept();
      client_work(client);
    }
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
void Server::client_work(std::shared_ptr<Socket> client) {
  client->setRcvTimeout(/*sec*/30, /*microsec*/0);
  while (true)
    try {
      std::string line = client->recv();
      Helper* ret = parser->query(line);
      CreateDBCommand *create_db_command = new CreateDBCommand(helper, line);
      app->setCommand(create_db_command);
      client->send("response: " + line + '\n');
    }
    catch (const std::exception &e) {
      std::cerr << "exception: " << e.what() << std::endl;
      return;
    }
}


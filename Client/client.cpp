#include <iostream>
#include <stdexcept>
#include <memory>               // shared_ptr
#include <errno.h>
#include <string.h>
#include <sstream>
#include "../socket/socket.hpp"

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    std::cerr << "usage: " << argv[0] << " host port" << std::endl;
    return 0;
  }

  try
  {
    std::string host(argv[1]);
    int port = std::stoi(argv[2]);

    Socket s;
    s.connect(host, port);
    s.setNonBlocked(true);
    std::string str;
    std::cin >> str;
    s.send(str);
    std::string line = s.recv();
    std::cout << "[]" << line << std::endl;
    s.close();
  }
  catch(const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}


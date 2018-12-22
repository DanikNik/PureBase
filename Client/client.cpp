//
// Created by daniknik on 14.12.18.
//

#include "simple_cmd_client.h"
//#include "mainwindow.h"
//#include <QApplication>

int main(int argc, char *argv[]) {
  try {
    Client client ;
    client.start();
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}

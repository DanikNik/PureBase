//
// Created by daniknik on 15.12.18.
//

#ifndef PUREBASE_CONNECTION_HEADERS_H
#define PUREBASE_CONNECTION_HEADERS_H



enum CONNECTION_SIGNALS {
  ERROR = 90,
  OK=100,
  REQUEST_HEADERS=101,
  CONNECT=201,
  DISCONNECT=202,
  TRANSACTION = 301,
  FILE_UPLOAD=302,
  FILE_START = 401,
  FILE_END = 402,
//  AUTHORIZATION_REQUIRED=501,
//  AUTHORIZE=502
};

//struct AuthInfo; TODO handshake

//std::string to_str(CONNECTION_SIGNALS signal){
//  std::stringstream ss;
//  ss << static_cast<int>(signal);
//  return ss.str();
//}

#endif //PUREBASE_CONNECTION_HEADERS_H

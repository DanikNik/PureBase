//
// Created by semyon on 02.12.18.
//

#ifndef PUREBASE_PG_CONNECTION_H
#define PUREBASE_PG_CONNECTION_H

#include <pqxx/pqxx>
#include <string>
#include <exception>

#define DEFAULT_OPTIONS "dbname = purebase username = postgres"

class PGConnect {
private:
    std::unique_ptr<pqxx::connection_base> Connect;
    void CreateConnect(std::string options);
    void Disconnect();
public:
    explicit PGConnect(std::string options);
    PGConnect();
    ~PGConnect();
    bool IsOpen();
};


#endif //PUREBASE_PG_CONNECTION_H

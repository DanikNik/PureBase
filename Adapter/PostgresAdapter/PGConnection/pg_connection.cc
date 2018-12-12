#include <utility>

//
// Created by semyon on 02.12.18.
//

#include "pg_connection.h"

PGConnect::PGConnect(std::string options) {
    CreateConnect(std::move(options));
}

PGConnect::PGConnect() {
    CreateConnect(DEFAULT_OPTIONS);
}

void PGConnect::Disconnect() {
    Connect->disconnect();
}

bool PGConnect::IsOpen() {
    return Connect->is_open();
}

PGConnect::~PGConnect() {
    this->Disconnect();
}

void PGConnect::CreateConnect(std::string options) {
    Connect = std::make_unique<pqxx::connection>(options);
}








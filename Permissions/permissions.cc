//
// Created by Иван Морозов on 03.12.2018.
//

#include "permissions.h"

Permissions::Permissions(bool can_write, bool can_read) {
  if(can_read) perm.push_back(CAN_READ);
  if(can_write) perm.push_back(CAN_WRITE);
}

bool Permissions::can_write() {
  return (std::find(perm.begin(), perm.end(), CAN_WRITE) != perm.end());
}

bool Permissions::can_read() {
  return (std::find(perm.begin(), perm.end(), CAN_READ) != perm.end());
}

void Permissions::set_read() {
  if(!can_read()) {
    perm.push_back(CAN_READ);
  } else {
    std::cout << "CAN READ IS ALSO SET";
  }
}

void Permissions::set_write() {
  if(!can_write()) {
    perm.push_back(CAN_WRITE);
  } else {
    std::cout << "CAN WRITE ALSO";
  }
}

bool Permissions::have_permissions() {
  return (!perm.empty());
}

bool Permissions::operator==(Permissions rhs) {
  if(this->can_read() == rhs.can_read() && this->can_write() == rhs.can_write()) {
    return true;
  } else {
    return false;
  }
}

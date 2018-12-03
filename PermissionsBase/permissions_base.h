//
// Created by Иван Морозов on 03.12.2018.
//

#ifndef PUREBASE_PERMISSIONS_BASE_H
#define PUREBASE_PERMISSIONS_BASE_H

#include <vector>

struct PermissionBase {
  PermissionBase() = default;
  enum permissions {CAN_READ, CAN_WRITE};
  virtual bool can_write() = 0;
  virtual bool can_read() = 0;

 protected:
  std::vector<permissions> perm;
};

#endif //PUREBASE_PERMISSIONS_BASE_H

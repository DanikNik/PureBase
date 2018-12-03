//
// Created by Иван Морозов on 03.12.2018.
//

#ifndef PUREBASE_WRITE_PERMISSIONS_H
#define PUREBASE_WRITE_PERMISSIONS_H

#include "../PermissionsBase/permissions_base.h"
#include <iostream>
#include <algorithm>

struct Permissions : public PermissionBase {
 public:
  Permissions() = default;
  Permissions(bool can_write, bool can_read);
  enum permissions { CAN_READ, CAN_WRITE };
  bool can_write() override;
  bool can_read() override;
  void set_write();
  void set_read();
  bool have_permissions();
  bool operator==(Permissions rhs);
 private:
  std::vector<permissions> perm;

};

#endif //PUREBASE_WRITE_PERMISSIONS_H

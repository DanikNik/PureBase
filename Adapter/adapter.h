//
// Created by semyon on 12.11.18.
//

#ifndef PUREBASE_ADAPTER_H
#define PUREBASE_ADAPTER_H

#include <iostream>
#include "../Helper/helper.h"

class Adapter: public Helper {
private:
    Helper helper;
public:
    Adapter(Helper);
    void* query();
};


#endif //PUREBASE_ADAPTER_H

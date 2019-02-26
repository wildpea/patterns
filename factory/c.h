#ifndef PATTERNS_FACTORY_C_H_
#define PATTERNS_FACTORY_C_H_


#include "base.h"

class C : public Base
{
public:
    C(int type) : Base(type) {}
    ~C(){}

    void process()
    {
        std::cout << "in C" << std::endl;
    }
};


#endif /* PATTERNS_FACTORY_C_H_ */

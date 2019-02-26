#ifndef PATTERNS_FACTORY_A_H_
#define PATTERNS_FACTORY_A_H_


#include "base.h"

class A : public Base
{
public:
    A(int type) : Base(type) {}
    ~A(){}

    void process()
    {
        std::cout << "in A" << std::endl;
    }
};


#endif /* PATTERNS_FACTORY_A_H_ */

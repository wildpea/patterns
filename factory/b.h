#ifndef PATTERNS_FACTORY_B_H_
#define PATTERNS_FACTORY_B_H_


#include "base.h"

class B : public Base
{
public:
    B(int type) : Base(type) {}
    ~B(){}

    void process()
    {
        std::cout << "in B" << std::endl;
    }
};


#endif /* PATTERNS_FACTORY_B_H_ */

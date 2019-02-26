#include "base.h"
#include "a.h"
#include "b.h"
#include "c.h"


std::shared_ptr<Base> Base::create_obj(int type)
{
    std::shared_ptr<Base> base;

    if (type == 1)
    {
        base = std::shared_ptr<Base>(new A(type));
    }
    else if (type == 2)
    {
        base = std::shared_ptr<Base>(new B(type));
    }
    else if (type == 3)
    {
        base = std::shared_ptr<Base>(new C(type));
    }

    return base;
}

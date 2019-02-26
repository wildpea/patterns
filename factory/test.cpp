#include "base.inl"

int main()
{
    std::shared_ptr<Base> base = Base::create_obj(1);
    if (base == NULL) return -1;

    base->process();
}

#ifndef PATTERNS_FACTORY_BASE_H_
#define PATTERNS_FACTORY_BASE_H_


#include <iostream>
#include <memory>

class Base
{
public:
    static std::shared_ptr<Base> create_obj(int type);
    virtual void process() = 0;

protected:
    Base(int type) : type_(type) {}
    virtual ~Base() {}

private:
    int type_;

    Base(const Base&);
    const Base& operator=(const Base&);
};


#endif /* PATTERNS_FACTORY_BASE_H_ */

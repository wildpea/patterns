/*
 * simpleFactory.h
 *
 *  Created on: 2016年2月17日
 *      Author: olivia.long
 *        TAPD: 
 * Description: 
 * 
 */

#ifndef SRC_PATTERNS_FACTORY_SIMPLEFACTORY_H_
#define SRC_PATTERNS_FACTORY_SIMPLEFACTORY_H_

#include <string>
using namespace std;

class Pizza{
public:
    void prepare(){}
    void bake(){}
    void cut(){}
    void box(){}
};
class CheesePizza: public Pizza{};
class ClamPizza: public Pizza{};
class VeggiePizza: public Pizza{};

class SimplePizzaFactory
{
public:
    Pizza* CreatePizza(string &type)
    {
        Pizza *pizza;
        if (type == "cheese")
        {
            pizza = new CheesePizza();
        } else if (type == "clam")
        {
            pizza = new ClamPizza();
        } else if (type == "veggie")
        {
            pizza = new VeggiePizza();
        }
        return pizza;
    }
};

class PizzaStore
{
public:
    PizzaStore(SimplePizzaFactory *factory)
    {
        factory_ = factory;
    }
    void orderPizza(string &type)
    {
        Pizza pizza;
        pizza = factory_->CreatePizza(type);

        pizza.prepare();
        pizza.bake();
        pizza.cut();
        pizza.box();

        return;
    }
private:
    SimplePizzaFactory *factory_;
};

#endif /* SRC_PATTERNS_FACTORY_SIMPLEFACTORY_H_ */

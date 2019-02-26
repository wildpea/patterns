/*
 * Pizza.h
 *
 *  Created on: 2016年3月13日
 *      Author: olivia.long
 *        TAPD: 
 * Description: 
 * 
 */

#ifndef SRC_PATTERNS_FACTORY_FACTORYFUNCTION_PIZZA_H_
#define SRC_PATTERNS_FACTORY_FACTORYFUNCTION_PIZZA_H_

#include <iostream>
#include <string>
using namespace std;

class Pizza
{
public:
    Pizza(){}
    virtual ~Pizza(){}
public:
    virtual void prepare(){}
    virtual void bake(){}
    virtual void cut(){}
    virtual void box(){}
    virtual string getName(){
        return name_;
    }
public:
    string name_;
};

class NYStyleCheesePizza: public Pizza{};
class NYStylePepperroniPizza: public Pizza{};
class NYStyleClamPizza: public Pizza{};
class NYStyleVeggiePizza: public Pizza{};

class ChicagoStyleCheesePizza: public Pizza{};
class ChicagoStylePepperroniPizza: public Pizza{};
class ChicagoStyleClamPizza: public Pizza{};
class ChicagoStyleVeggiePizza: public Pizza{};


class PizzaStore
{
public:
    PizzaStore() : ptr_pizza(NULL){}
    virtual ~PizzaStore(){}
public:
    virtual void CreatePizza(string type) = 0;
    virtual void oderPizza(){
        cout << "pizza: " << ptr_pizza->getName() << " is in order!" << endl;
        ptr_pizza->prepare();
        ptr_pizza->bake();
        ptr_pizza->cut();
        ptr_pizza->box();
    }
public:
    Pizza *ptr_pizza;
};

class NYStylePizzaStore: public PizzaStore
{
public:
    void CreatePizza(string type)
    {
        if (type == "cheese")
        {
            ptr_pizza = new NYStyleCheesePizza();
        } else if (type == "pepperroni")
        {
            ptr_pizza = new NYStylePepperroniPizza();
        } else if (type == "clam")
        {
            ptr_pizza = new NYStyleClamPizza();
        } else if (type == "veggie")
        {
            ptr_pizza = new NYStyleVeggiePizza();
        }
    }
};

class ChicagoStylePizzaStore: public PizzaStore
{
public:
    void CreatePizza(string type)
    {
        if (type == "cheese")
        {
            ptr_pizza = new ChicagoStyleCheesePizza();
        } else if (type == "pepperroni")
        {
            ptr_pizza = new ChicagoStylePepperroniPizza();
        } else if (type == "clam")
        {
            ptr_pizza = new ChicagoStyleClamPizza();
        } else if (type == "veggie")
        {
            ptr_pizza = new ChicagoStyleVeggiePizza();
        }
    }
};


#endif /* SRC_PATTERNS_FACTORY_FACTORYFUNCTION_PIZZA_H_ */

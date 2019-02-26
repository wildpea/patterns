/*
 * duck.h
 *
 *  Created on: 2016年1月6日
 *      Author: olivia.long
 *        TAPD: 
 * Description: 
 * 
 */

#ifndef SRC_PATTERNS_STRATEGY_DUCK_H_
#define SRC_PATTERNS_STRATEGY_DUCK_H_

#include <iostream>
#include <string>
using namespace std;

class FlyBehavior
{
public:
    FlyBehavior(){}
    virtual ~FlyBehavior(){}
    virtual void fly(){}
};

class FlyNoWay : public FlyBehavior
{
public:
    FlyNoWay(){}
    ~FlyNoWay(){}
    void fly(){
        cout << "fly no way!" << endl;
    }
};

class FlyRocketPowered: public FlyBehavior
{
public:
    FlyRocketPowered(){}
    ~FlyRocketPowered(){}
    void fly(){
        cout << "i can fly with a rocket!" << endl;
    }
};

class QuackBehavior
{
public:
    QuackBehavior(){}
    virtual ~QuackBehavior(){}
    virtual void quack(){}
};

class Quack: public QuackBehavior
{
public:
    Quack(){}
    ~Quack(){}
    void quack()
    {
        cout << "quack" << endl;
    }
};

class Zizi: public QuackBehavior
{
public:
    Zizi(){}
    ~Zizi(){}
    void quack()
    {
        cout << "zizi" << endl;
    }
};



class Duck
{
public:
    Duck(){}
    ~Duck(){}

    void swim(){}
    void display(){}
    void quack()
    {
        quackBehavior->quack();
    }
    void fly()
    {
        flyBehavior->fly();
    }
    void setQuackBehavior(QuackBehavior *quack)
    {
        quackBehavior = quack;
    }
    void setFlyBehavior(FlyBehavior *fly)
    {
        flyBehavior = fly;
    }

public:
    FlyBehavior *flyBehavior;
    QuackBehavior *quackBehavior;

};

class MallardDuck: public Duck
{
public:
    MallardDuck()
    {
        quackBehavior = new Quack();
    }
    ~MallardDuck()
    {
        delete quackBehavior;
    }
};

class ModelDuck : public Duck
{
public:
    ModelDuck()
    {
        flyBehavior = new FlyNoWay();
    }
    ~ModelDuck()
    {
        delete flyBehavior;
    }
};

//class RedheadDuck: public Duck
//{
//
//};

class RubberDuck: public Duck
{
public:
    RubberDuck()
    {
        quackBehavior = new Zizi();
    }
    ~RubberDuck()
    {
        delete quackBehavior;
    }
};

//class DecoyDuck: public Duck
//{
//
//};


#endif /* SRC_PATTERNS_STRATEGY_DUCK_H_ */

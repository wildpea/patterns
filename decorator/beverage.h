/*
 * beverage.h
 *
 *  Created on: 2016年1月14日
 *      Author: olivia.long
 *        TAPD: 
 * Description: 
 * 
 */

#ifndef SRC_PATTERNS_DECORATOR_BEVERAGE_H_
#define SRC_PATTERNS_DECORATOR_BEVERAGE_H_

#include <iostream>
#include <string>
using namespace std;

enum BEVERAGE_SIZE
{
    SMALL = 1,
    MIDDLE = 2,
    BIG = 3
};

class Beverage
{
public:
    Beverage(BEVERAGE_SIZE size = MIDDLE){
        size_ = size;
    }
    virtual ~Beverage(){}
    virtual string getDescription() = 0;
    virtual int cost() = 0;
    virtual BEVERAGE_SIZE getSize(){return size_;}
    virtual void setSize(BEVERAGE_SIZE size){
        size_ = size;
    }
    void display()
    {
        cout << "description: " << getDescription() << "  cost: " << cost() << endl;
    }
public:
    BEVERAGE_SIZE size_;
};


class Espresso : public Beverage
{
public:
    Espresso(BEVERAGE_SIZE size = MIDDLE)
        : Beverage(size)
    {}
    ~Espresso(){}
    string getDescription()
    {
        return "I am espresso!";
    }
    int cost()
    {
        switch (size_)
        {
            case SMALL:
                return 20;
            case BIG:
                return 28;
            case MIDDLE:
            default:
                return 25;
        }
    }
};

class Decaf : public Beverage
{
public:
    Decaf(BEVERAGE_SIZE size = MIDDLE)
        : Beverage(size)
    {}
    ~Decaf(){}
    string getDescription()
    {
        return "I am decaf!";
    }
    int cost()
    {
        switch (size_)
        {
            case SMALL:
                return 25;
            case BIG:
                return 35;
            case MIDDLE:
            default:
                return 32;
        }
    }
};


class CondimentDecorator: public Beverage
{
public:
    CondimentDecorator(){}
    virtual ~CondimentDecorator(){}
    virtual string getDescription() = 0;
    virtual int cost() = 0;

public:
    Beverage *wrappered;
};

class Milk: public CondimentDecorator
{
public:
    Milk(Beverage *p_beverage){
        wrappered = p_beverage;
        size_ = wrappered->size_;
    }
    ~Milk(){}
    string getDescription()
    {
        return wrappered->getDescription() + " with milk";
    }
    int cost()
    {
        int cst = 0;
        switch (wrappered->getSize())
        {
            case SMALL:
                cst = 3;
                break;
            case BIG:
                cst = 7;
                break;
            case MIDDLE:
            default:
                cst = 5;
        }
        return wrappered->cost() + cst;
    }
};

class Mocha: public CondimentDecorator
{
public:
    Mocha(Beverage *p_beverage){
        wrappered = p_beverage;
        size_ = wrappered->size_;
    }
    ~Mocha(){}
    string getDescription()
    {
        return wrappered->getDescription() + " with mocha";
    }
    int cost()
    {
        int cst = 0;
        switch (wrappered->getSize())
        {
            case SMALL:
                cst = 4;
                break;
            case BIG:
                cst = 8;
                break;
            case MIDDLE:
            default:
                cst = 6;
        }
        return wrappered->cost() + cst;
    }
};

#endif /* SRC_PATTERNS_DECORATOR_BEVERAGE_H_ */

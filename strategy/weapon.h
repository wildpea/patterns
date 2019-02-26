/*
 * weapon.h
 *
 *  Created on: 2016年1月8日
 *      Author: olivia.long
 *        TAPD: 
 * Description: 
 * 
 */

#ifndef SRC_PATTERNS_STRATEGY_WEAPON_H_
#define SRC_PATTERNS_STRATEGY_WEAPON_H_

#include <iostream>
using namespace std;


class WeaponBehavior
{
public:
    WeaponBehavior(){}
    virtual ~WeaponBehavior(){}
    virtual void useWeapon() = 0;
};

class KnifeBehavior: public WeaponBehavior
{
public:
    KnifeBehavior(){}
    ~KnifeBehavior(){}
    void useWeapon()
    {
        cout << "use knife" << endl;
    }
};

class AxeBehavior: public WeaponBehavior
{
public:
    AxeBehavior(){}
    ~AxeBehavior(){}
    void useWeapon()
    {
        cout << "use axe" << endl;
    }
};

class BowAndArrowBehavior: public WeaponBehavior
{
public:
    BowAndArrowBehavior(){}
    ~BowAndArrowBehavior(){}
    void useWeapon()
    {
        cout << "use bow and arrow" << endl;
    }
};


class Character
{
public:
    void fight()
    {
        weapon->useWeapon();
    }
    void setWeapon(WeaponBehavior *new_weapon)
    {
        weapon = new_weapon;
    }
public:
    WeaponBehavior *weapon;
};

class Queen: public Character
{
public:
    Queen(){
        cout << "I am a Queen!" << endl;
        weapon = new BowAndArrowBehavior();
    }
    ~Queen(){
        delete weapon;
    }
};

class King: public Character
{
public:
    King(){
        cout << "I am a king!" << endl;
        weapon = new AxeBehavior();
    }
    ~King(){
        delete weapon;
    }
};


#endif /* SRC_PATTERNS_STRATEGY_WEAPON_H_ */

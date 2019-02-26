/*
 * main.cpp
 *
 *  Created on: 2016年1月6日
 *      Author: olivia.long
 *        TAPD: 
 * Description: 
 * 
 */

#include <iostream>
#include "duck.h"
#include "weapon.h"
using namespace std;

int main()
{
    MallardDuck duck;
    duck.quack();

    RubberDuck duck2;
    duck2.quack();

    ModelDuck duck3;
    duck3.fly();

    FlyRocketPowered *rocket = new FlyRocketPowered;
    duck3.setFlyBehavior(rocket);
    duck3.fly();

    King king;
    king.fight();
    KnifeBehavior *knife = new KnifeBehavior;
    king.setWeapon(knife);
    king.fight();
}

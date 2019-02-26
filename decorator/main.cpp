/*
 * main.cpp
 *
 *  Created on: 2016年1月14日
 *      Author: olivia.long
 *        TAPD: 
 * Description: 
 * 
 */

#include <iostream>
#include "beverage.h"
using namespace std;

int main()
{
    Espresso espresso;
    espresso.display();

    Milk milk(&espresso);
    milk.display();

    Mocha mocha(&milk);
    mocha.display();

    Mocha mocha2(&mocha);
    mocha2.display();


    Decaf decaf(BIG);
    decaf.display();

    Milk milk_decaf(&decaf);
    milk_decaf.display();

    Mocha mocha_decaf(&milk_decaf);
    mocha_decaf.display();

    Mocha mocha_decaf2(&mocha_decaf);
    mocha_decaf2.display();

    return 0;
}



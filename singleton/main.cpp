/*
 * main.cpp
 *
 *  Created on: 2016年3月27日
 *      Author: olivia.long
 *        TAPD: 
 * Description: 
 * 
 */

#include <iostream>
#include <string>
#include "singleton.h"


class Haha
{
public:
    void print()
    {
        std::cout << "haha" << std::endl;
    }
};

int main()
{
    Singleton<Haha>::instance()->print();
    return 0;
}


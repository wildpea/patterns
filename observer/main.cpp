/*
 * main.cpp
 *
 *  Created on: 2016年1月9日
 *      Author: olivia.long
 *        TAPD: 
 * Description: 
 * 
 */


#include <iostream>
#include "weather_data.h"

using namespace std;

int main()
{
    WeatherData weather_data;
    CurrentConditionDisplay current_display(&weather_data);
    StatisticDisplay statistic_display(&weather_data);

    weather_data.setMeasurements(1, 2, 3);
    weather_data.setMeasurements(4, 5, 6);

    return 0;
}

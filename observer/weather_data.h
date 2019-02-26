/*
 * weather_data.h
 *
 *  Created on: 2016年1月9日
 *      Author: olivia.long
 *        TAPD: 
 * Description: 
 * 
 */

#ifndef SRC_PATTERNS_OBSERVER_WEATHER_DATA_H_
#define SRC_PATTERNS_OBSERVER_WEATHER_DATA_H_

#include <string>
#include <vector>
#include <algorithm>

#include "observer.h"

using namespace std;

class WeatherData: public Subject
{
public:
    WeatherData()
            : temperature_(0), humidity_(0), pressure_(0)
    {
    }
    ~WeatherData()
    {
    }

    void registerObserver(Observer *obs)
    {
        observer_arr_.push_back(obs);
    }

    void removeObserver(Observer *obs)
    {

        remove(observer_arr_.begin(), observer_arr_.end(), obs);
    }

    void notifyObserver()
    {
        for (auto iter = observer_arr_.begin(); iter != observer_arr_.end(); ++iter)
        {
            (*iter)->update(temperature_, humidity_, pressure_);
        }
    }

    void setMeasurements(float temperature, float humidity, float pressure)
    {
        temperature_ = temperature;
        humidity_ = humidity;
        pressure_ = pressure;
        notifyObserver();
    }

private:
    vector<Observer *> observer_arr_;
    float temperature_;
    float humidity_;
    float pressure_;
};

class Display
{
public:
    Display()
    {
    }
    virtual ~Display()
    {
    }
    virtual void display() = 0;
};

class CurrentConditionDisplay: public Observer, public Display
{
public:
    CurrentConditionDisplay(WeatherData *p_weather_data)
    {
        temperature_ = 0;
        humidity_ = 0;
        pressure_ = 0;
        p_weather_data_ = p_weather_data;
        p_weather_data_->registerObserver(this);
    }
    ~CurrentConditionDisplay()
    {
    }
    void update(float temperature, float humidity, float pressure)
    {
        temperature_ = temperature;
        humidity_ = humidity;
        pressure_ = pressure;
        display();
    }
    void display()
    {
        cout << "temperature: " << temperature_ << "\t"
                << "humidity: " << humidity_ << "\t"
                << "pressure: " << pressure_ << endl;
    }

private:
    WeatherData *p_weather_data_;
    float temperature_;
    float humidity_;
    float pressure_;
};

class StatisticDisplay: public Observer, public Display
{
public:
    StatisticDisplay(WeatherData *p_weather_data){
        min_temperature_ = 0;
        max_temperature_ = 0;
        p_weather_data_ = p_weather_data;
        p_weather_data_->registerObserver(this);
    }
    ~StatisticDisplay(){}
    void update(float temperature, float humidity, float pressure)
    {
        if (min_temperature_ == 0)
        {
            min_temperature_ = temperature;
        } else
        {
            min_temperature_ = temperature < min_temperature_ ? temperature : min_temperature_;
        }

        if (max_temperature_ == 0)
        {
            max_temperature_ = temperature;
        } else
        {
            max_temperature_ = temperature > max_temperature_ ? temperature : max_temperature_;
        }
        display();
    }
    void display(){
        cout<< "min temperature: " << min_temperature_ << "\t"
                << "max temperature: " << max_temperature_ << endl;
    }
private:
    WeatherData *p_weather_data_;
    float min_temperature_;
    float max_temperature_;
};

#endif /* SRC_PATTERNS_OBSERVER_WEATHER_DATA_H_ */

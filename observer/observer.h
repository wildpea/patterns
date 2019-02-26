/*
 * observer.h
 *
 *  Created on: 2016年1月9日
 *      Author: olivia.long
 *        TAPD: 
 * Description: 
 * 
 */

#ifndef SRC_PATTERNS_OBSERVER_OBSERVER_H_
#define SRC_PATTERNS_OBSERVER_OBSERVER_H_


class Observer
{
public:
    Observer()
    {
    }
    virtual ~Observer()
    {
    }
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

class Subject
{
public:
    Subject()
    {
    }
    virtual ~Subject()
    {
    }
    virtual void registerObserver(Observer *obs) = 0;
    virtual void removeObserver(Observer *obs) = 0;
    virtual void notifyObserver() = 0;
};


#endif /* SRC_PATTERNS_OBSERVER_OBSERVER_H_ */

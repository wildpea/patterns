/*
 * singleton.h
 *
 *  Created on: 2016年3月27日
 *      Author: olivia.long
 *        TAPD: 
 * Description: 
 * 
 */


template<typename T>
class Singleton
{
public:
    static T *instance()
    {
        return &instance_;
    }
private:
    Singleton(){}
    ~Singleton(){}

    static T instance_;
};

template<typename T> T Singleton<T>::instance_;

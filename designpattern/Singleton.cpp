/*
 * Singleton：单例设计模式
 * 单例设计模式确保一个类只有一个实例，并且只能通过类内部方法访问此实例。
 * 当你有个“全局”对象，并且只会有一个这种实例时，这个模式特别好用。
 * 比如，在实现“餐馆”时，我们可能想让它只有一个“餐馆”实例。
 */

#include <iostream>
#include <string>

using namespace std;

class Singleton
{
public:
    static Singleton* GetInstance()
    {
        if(singleton == NULL)
        {
            singleton = new Singleton();
        }
        return singleton;
    }        

private:
    static Singleton* singleton;
};


Singleton* Singleton::singleton = NULL;

class SingletonMultiThread
{
public:
    static SingletonMultiThread* GetInstance()
    {
        if(singleton == NULL)
        {
            if(singleton == NULL)
            {
                singleton = new SingletonMultiThread();
            }    
        }
        return singleton;
    
    }

private:
    static SingletonMultiThread* singleton;
};

SingletonMultiThread* SingletonMultiThread::singleton = NULL;

int main()
{
    return 0;
}

/*
原则上，C++类中私有变量不允许在类之外的其他任何地方访问，一般来说功能完善的类都会提供get,set方法来操作类属性值，还有就是就是通过友元访问。
但如果没有get、set方法都没有提供，也没有定义友元，比如使用的是第三方提供的.o（或者动态库）来进行开发的，并且实际应用中我们确确实实需要改变其中某个对象的一个私有参数，有没有什么办法呢？
还有一种比较文艺青年的方法，我们知道，一个进程有程序段和数据段，如果我们知道了对象的数据空间，那么得到该对象的成员变量值也就很简单了，而实际上，对象数据段的首地址其实就是对象地址。
*/

#include <iostream>
#include <string>
using namespace std;

class center
{
public:
    void setX(float _x){x=_x;}
    void setY(float _y){y=_y;}
    void setMeanValue(float avg){meanValue=avg;}
    float getX(){return x;}
    float getY(){return y;}
    float getMeanValue(){return meanValue;}
    center():x(0.0),y(0.0),meanValue(0.0){}
private:
    float x;
    float y;
    float meanValue;
};

int main()
{
 center A;
 //普通青年的赋值方法;
 A.setX(1.0);
 A.setY(4.0);
 A.setMeanValue(13.0);
 cout<<A.getX()<<" "<<A.getY()<<" "<<A.getMeanValue()<<endl;
 
 //文艺青年的赋值方法;
 //*((float*)&A):将center对象A的内存空间强制类型转化为用int*指向的内存空间，访问该内存
 float tmp = *((float*)&A);
 cout<<tmp<<endl;//输出A.x的值
 tmp = *((float*)&A + 1);
 cout<<tmp<<endl;//输出A.y的值
 *((float*)&A + 2)=2;//修改A.meanValue的值
 cout<<A.getMeanValue()<<endl;


 while(1);
 return 0;
}

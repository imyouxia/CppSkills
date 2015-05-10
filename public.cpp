/*
  1.Public的变量可以在类中以及外部（对象）访问到
  2.Private只可以在类/友元中访问到

*/
#include <iostream>

using namespace std;

class Test{
    public:
    int publicx;
    void publicm();

protected: // 当前类和子类
    int protectedx;
    void protectedm();

private:
    int privatex;
    void privatem();
};


void Test::privatem(){
    cout << "Privatem():\n";
    this->publicx = 1111;
    cout << this->publicx << endl;
}

void Test::protectedm(){
    cout << "Protectdm():\n";
}

void Test::publicm(){
    cout << "Publicm():\n";
}

int main(){
    Test t;
    //t.protectedm();
    //t.privatem();
    t.publicm();
    while(1);
    return 0;
}


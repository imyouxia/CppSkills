/*
  类中的私有成员可以在以下四个地方被访问：
  1.当前类中;
  2.类的友元函数；//类的友元函数就是在类中把普通的函数用friend进行声明
  3.类的友元成员函数；//类的友元成员函数就是在类中把另一个类的成员函数进行friend进行声明
  4.类的友元类中所有成员函数； //类的友元类就是在类中把另一个类用friend进行声明

*/

#include <iostream>

using namespace std;

// 类的友元函数
class Stu{
    friend void test2();
private:
    int age;
    void show()
    {
        cout << "Show!\n" << endl; 
    };
};

void test1(){
    Stu stu;
    //stu.age = 23; //错
    //stu.show();
}

void test2(){
    Stu stu;
    stu.age = 23;
    stu.show();
}

class Teacher{
public:
    void teacher1();
    void teacher2();
};

//类的友元成员函数
class Stu1{
    friend void Teacher::teacher2();
private:
    int age;
    void show(){
        cout << "Stu1"<<endl;
    };
};

void Teacher::teacher1(){
    Stu1 stu;
    //stu.age = 2; //错
    //stu.show();
}

void Teacher::teacher2(){
    Stu1 stu;
    stu.age = 2; 
    stu.show();
}


// 类的友元类
class Stu2{
    friend class Teacher1;
private:
    int age;
    void show()
    {
        cout << "Stu2\n" << endl;
    };
};

class Teacher1{
public:
    void test1();
    void test2();
};

void Teacher1::test1(){
    Stu2 stu;
    stu.age = 2;
    stu.show();
}

void Teacher1::test2(){
    Stu2 stu;
    stu.age = 2;
    stu.show();
}

int main(){
    test1();
    test2();
    Teacher t;
    t.teacher1();
    t.teacher2();
    Teacher1 t1;
    t1.test1();
    t1.test2();
    return 0;  
}



/*
	工厂模式属于创建型模式，大致可以分为三类：
	简单工厂模式、工厂方法模式、抽象工厂模式。
*/

/*
	简单工厂模式 ： 需要在工厂类中做判断，从而创造相应的产品。当增加新的产品时，就需要修改工厂类。
	举例：
	有一家生产处理器核的厂家，它只有一个工厂，能够生产两种型号的处理器核。客户需要什么样的处理器核，一定要显示地告诉生产工厂。
*/

enum CTYPE {COREA,COREB};
class SingleCore
{
public:
	virtual void Show() = 0;	
};

// 单核A
class SingleCoreA : public SingleCore
{
public:
	void Show() {cout << "SingleCore A"<<endl;}	
};

// 单核B
class SingleCoreB : public SingleCore
{
public:
	void Show() {cout<<"SingleCore B"<<endl;}	
};

// 唯一的工厂，可以生产两种型号的处理器核，在内部判断
class Factory
{
public:
	SingleCore* CreateSingleCore(enum CTYPE ctype)
	{
		if(ctype == COREA) //工厂内部判断
			return new SingleCoreA();  //生产核A
		else if(ctype == COREB)
		{
			return new SingleCoreB(); //生产核B
		}
		else
			return NULL;
	}	
	
};


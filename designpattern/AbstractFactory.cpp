/* 工厂方法模式也有缺点，每增加一种产品，就需要增加一个对象的工厂。如果这家公司发展迅速，推出了很多新的处理器核，那么就要新开设相应的新工厂。在C++实现中，就是要定义一个个的工厂类。显然，相比简单工厂模式，工厂方法模式需要更多的类定义。
*/
/*
    既然有了简单工厂模式和工厂方法模式，为什么还要有抽象工厂模式呢？它到底有什么作用呢？还是举例子，这家公司的技术不断进步，不仅可以生产单核处理器，也能生产多喝处理器。现在简单工厂模式和工厂方法模式都鞭长莫及。抽象工厂模式登场了。它的定义为提供一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类。
*/
    
// 单核
class SingleCore
{
public:
	virtual void Show() = 0;	
};

class SingleCoreA : public SingleCore
{
public:
	void Show() {cout << "Single Core A"<<endl;}	
};

class SingleCoreB : public SingleCore
{
public:
	void Show() {cout << "Single Core B"<<endl;}
};

// 多核
class MultiCore
{
public:	
	virtual void Show() = 0;
};

class MultiCoreA : public MultiCore
{
public:
	void Show() {cout<<"Multi Core A"<<endl;}	
};

class MultiCoreB : public MultiCore
{
public:
	void Show() {cout<<"Multi Core B"<<endl;}	
};

// 工厂
class CoreFactory
{
public:
	virtual SingleCore* CreateSingleCore() = 0;
	virtual MultiCore* CreateMultiCore() = 0;						
};

// 工厂A，专门用来生产A型号的处理器
class FactoryA : public CoreFactory
{
public:
	SingleCore* CreateSingleCore() {return new SingleCoreA();}
	MultiCore* CreateMultiCore() {return new MultiCoreA();}	
};

// 工厂B，专门用来生产B型号的处理器
class FactoryB : public CoreFactory
{
public:
	SingleCore* CreateSingleCore() {return new SingleCoreB();}
	MultiCore* CreateMultiCore() {return new MultiCoreB();}	
};

/*
 * 工厂方法模式，定义一个用于创建对象的接口，让子类决定实例化哪一个类。Factory Method 使一个类的实例化延迟到其子类。
 *  比如要A型号的核，就找A工厂要；否则找B工厂要，不再需要告诉工厂需要什么具体的处理区核了。
 */
 
 class SingleCore
 {
 public:
 	virtual void Show() = 0;	
 };
 //单核A
 class SingleCoreA  : public SingleCore
 {
 public:
 	void Show() {cout << "SingleCore B"<<endl;}	
 };
 // 单核B
 class SingleCoreB : public SingleCore
 {
 public:
 	void Show() {cout << "SingleCore B"<<endl;}
 };
 
 class Factory
 {
 public:
 	virtual SingleCore* CreateSingleCore() = 0;	
 };
 
 // 生产A核的工厂
 class FactoryA : public Factory
 {
 public:
 	SingleCoreA* CreateSingleCore() {return new SingleCoreA;}	
 };
 
 // 生产B核的工厂
 class FactoryB : public Factory
 {
 public:
 	SingleCoreB* CreateSingleCore() {return new SingleCoreB;}
 }
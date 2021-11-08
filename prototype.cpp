/*原型模式是对一个类的拷贝，也许有人说那这和拷贝构造函数有什么区别呢？ 
区别在于原型模式里，你可以保存基类指针，最后生成的是这个指针真正指向的子类，
而拷贝构造函数你必须搞一个具体的类进去，生成的object也是固定的。
通俗来说就是如何想考拷贝一个基类指针指向一个派生类对象的时候就要用原型模式

eg:定义一个Prototype基类
这里我们拷贝了Prototype的派生类ConcretePrototype*/
#include <iostream>
using namespace std;
class Prototype {
public:
    virtual Prototype* Clone() const = 0;
    virtual ~Prototype() {

    }
protected:
    Prototype(){

    }
};

class ConcretePrototype:public Prototype {
public:
    ConcretePrototype() {

    }
    ConcretePrototype(const ConcretePrototype &sp) {
        *this = sp;
        cout<<"ConcretePrototype copy..."<<endl;
    }
    virtual Prototype* Clone() const{
        return new ConcretePrototype(*this);
    }
    ~ConcretePrototype() {

    }
};

int main(){
    Prototype* p = new ConcretePrototype();
    Prototype* p1 = p->Clone();
    Prototype* p2 = p->Clone();
    
}
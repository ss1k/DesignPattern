/*Definition:A utility class that creates an instance of a class from a family of derived classes
the factory method defines a method for creating the objects, which subclasses can then override to specify 
the derived type that will be created.抽象出一些类的公共 接口以形成抽象基类或者接口。这样我们可以通过
声明一个指向基类的指针来指向实际的子 类实现,达到了多态的目的。

eg：抽象出所有电脑的基础类Computer
针对基础类设计接口price，description
不同的电脑型号集成基础类来实现接口price，description
通过工厂CompputerFactory来判断此时客户端需要什么样的实体对象
这样我们可以通过声明一个指向基类的指针来指向实际的子 类实现,达到了多态的目的*/

#include <iostream>
using namespace std;
class Computer {
public:
    virtual void price() = 0;
    virtual void description() = 0;
    virtual ~Computer() {}
};

class Laptop: public Computer {
public:
    void price(){
        cout<<"400$"<<endl;
    }
    void description() {
        cout<<"Laptops are mobile, portable and multimedia"<<endl;
    }
    virtual ~Laptop(){}
};

class Desktop: public Computer {
public:
    void price(){
        cout<<"1000$"<<endl;
    }
    void description() {
        cout<<"Desktops are fixed "<<endl;
    }
    virtual ~Desktop(){}
};

class ComputerFactory{
public:
    static Computer *NewComputer(const string &description) {
        if(description=="laptop")
            return new Laptop;
        if(description=="desktop")
            return new Desktop;
        return NULL;
    }
};

int main() {
    Computer *computer1 = ComputerFactory::NewComputer("laptop");
    computer1->price();
    computer1->description();

    Computer *computer2 = ComputerFactory::NewComputer("desktop");
    computer2->price();
    computer2->description();
}

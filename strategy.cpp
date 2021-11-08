/*Defines a family of algorithms, encapsulates each one, 
and make them interchangeable. Strategy lets the algorithm vary independently from clients who use it.

eg:通过context对不同的策略进行封装，减小算法的改变对客户端的影响
*/
#include <iostream>
using namespace std;

class Strategy {
public:
    Strategy() {}
    virtual void algorithmInterface(){};
    virtual ~Strategy() {}
};

class ConcreteStrategyA: public Strategy {
public:
    ConcreteStrategyA():Strategy() {

    }
    void algorithmInterface() {
        cout<<"algorithmInterfaceA"<<endl;
    }
    ~ConcreteStrategyA(){
        
    }
};

class ConcreteStrategyB: public Strategy {
public:
    ConcreteStrategyB():Strategy() {

    }
    void algorithmInterface() {
        cout<<"algorithmInterfaceB"<<endl;
    }
    ~ConcreteStrategyB(){
        
    }
};

class Context {
public:
    Context(Strategy* strategy) {
        this->strategy = strategy;
    }
    void contextInterface() {
        this->strategy->algorithmInterface();
    }
private:
    Strategy* strategy;
};

int main() {
    Context* context;
    context = new Context(new ConcreteStrategyA());
    context->contextInterface();
    context = new Context(new ConcreteStrategyB());
    context->contextInterface();
}
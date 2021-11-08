/*The Bridge Pattern is used to separate out the interface from its implementation. 
Doing this gives the flexibility so that both can vary independently.
桥接模式将抽象部门与它的实现部分分离，使他们独立地变化 继承是一种强耦合结构。
父类变化子类一定变化，所以我们在使用继承的时候一定要遵循"is a"的关系，当关系不是"is a"的关系时 我们就要考虑使用对象的合成或者聚合。

eg: 本例用描述两个不同手机里面的不同的两个功能，手机分别为Android和Iphone。
两个功能分别为游戏和联系人清单*/
#include <iostream>
using namespace std;

class Handsetsoft{
public:
    Handsetsoft(){

    }
    virtual void run() = 0;
    ~Handsetsoft(){

    }

};
class HandsetGame:public Handsetsoft{
public:
    HandsetGame():Handsetsoft(){

    }
    virtual void run() {
        cout<<"run game"<<endl;
    }
    ~HandsetGame(){

    }
};

class HandsetAddressList:public Handsetsoft{
public:
    HandsetAddressList():Handsetsoft(){
        
    }
    virtual void run() {
        cout<<"run addresslist"<<endl;
    }
    ~HandsetAddressList(){

    }
};

class HandsetBrand{
public:
    HandsetBrand(){

    }
    virtual void run() {}
    virtual void setHandsetsoft(Handsetsoft* soft) {
        this->soft = soft;
    }
    virtual ~HandsetBrand(){
        delete soft;
    }
protected:
    Handsetsoft* soft;
};
class Iphone:public HandsetBrand {
public:
    Iphone():HandsetBrand(){

    }
    virtual void run() {
        soft->run();
    }
    ~Iphone(){

    }
};

class Android:public HandsetBrand {
public:
    Android():HandsetBrand(){
        
    }
    virtual void run() {
        soft->run();
    }
    ~Android(){
        
    }
};

int main() {
    HandsetBrand* iphone = new Iphone();
    iphone->setHandsetsoft(new HandsetGame());
    iphone->run();

    HandsetBrand* android = new Android();
    iphone->setHandsetsoft(new HandsetAddressList());
    iphone->run();
}
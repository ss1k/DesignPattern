#include <iostream>
#include <string>
using namespace std;

class SchoolGirl {
public:
    string getName();
    void setName(string name);
private:
    string name;
};

class IGiveGift {
public:
    IGiveGift();
    virtual void GiveDolls() = 0;
    virtual void GiveFlowers() = 0;
    ~IGiveGift();
};

class Pursuit:public IGiveGift {
public:
    Pursuit(SchoolGirl* mm);
    virtual void GiveDolls();
    virtual void GiveFlowers();
    ~Pursuit();
private:
    SchoolGirl* mm;
};

class Proxy: public IGiveGift {
public:
    Proxy(SchoolGirl* mm);
    virtual void GiveDolls();
    virtual void GiveFlowers();
    ~Proxy();
private:
    Pursuit* gg;
};

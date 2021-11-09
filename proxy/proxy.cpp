#include "proxy.h"

Pursuit::Pursuit(SchoolGirl* mm) {
    this->mm = mm;
}

Pursuit::~Pursuit() {
    delete mm;
}

void Pursuit::GiveDolls() {
    cout<<mm->getName()<<":give you a doll."<<endl;
}

void Pursuit::GiveFlowers() {
    cout<<mm->getName()<<":give you a flower."<<endl;
}

Proxy::Proxy(SchoolGirl* mm) {
    gg = new Pursuit(mm);
}

Proxy::~Proxy() {
    delete gg;
}

void Proxy::GiveDolls() {
    gg->GiveDolls();
}

void Proxy::GiveFlowers() {
    gg->GiveFlowers();
}

string SchoolGirl::getName() {
    return this->name;
}

void SchoolGirl::setName(string name) {
    this->name = name;
}

IGiveGift::IGiveGift() {

}
IGiveGift::~IGiveGift() {
    
}
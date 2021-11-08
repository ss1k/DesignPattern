#pragma once
class State;
class Work {
public:
    Work();
    void setHour(double hour);
    void setState(State* s);
    double getHour();
    void writeProgram();
private:
    State* current;
    double hour;
};
#pragma once
class Work;

class State {
public:
    State();
    virtual void writeProgram(Work* w) = 0;
    virtual ~State();
};

class AfternoonState:public State{
public:
    AfternoonState();
    virtual void writeProgram(Work* w);
    virtual ~AfternoonState();
};

class NoonState:public State{
public:
    NoonState();
    virtual void writeProgram(Work* w);
    virtual ~NoonState();
};

class ForenoonState:public State{
public:
   ForenoonState();
    virtual void writeProgram(Work* w);
    virtual ~ForenoonState();
};
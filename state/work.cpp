#include<iostream>
#include"work.h"
#include"state.h"
using namespace std;
Work::Work(){
	current = new ForenoonState();
}
void Work::setHour(double hour){
	this->hour = hour;
}
void Work::setState(State* s){
	this->current = s;
}
double Work::getHour(){
	return hour;
}
void Work::writeProgram(){
	this->current->writeProgram(this);
}
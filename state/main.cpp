/*状态模式主要解决的是当控制一个对象状态转换的条件表达式过于复杂时的情况。
把状态的判断逻辑转化到表示不同状态的一系列类当中，可以把复杂的判断逻辑简单化

eg:这例子描述一位程序员在一天不同的不同上班时间的工作状态，我们用状态模式来表示
State基类定义接口，然后分别由AfternoonState,NoonState,ForenoonState继承这个基础类实现相应的接口
Work 类有设置时间函数setHour，设置状态函数setState，获取时间getHour和写程序writeprogramm。
其中仅仅setHour是给客户端调用的
*/
#include<iostream>
using namespace std;
#include "work.h"
#include "state.h"
int main(){
	Work* programmer = new Work();
	programmer->setHour(10);
	programmer->writeProgram();
	programmer->setHour(12);
	programmer->writeProgram();
	programmer->setHour(15);
	programmer->writeProgram();
	programmer->setHour(18);	
	programmer->writeProgram();
	
}
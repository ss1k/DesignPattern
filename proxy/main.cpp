/*代理模式：为其他对象提供一种代理以控制对这个对象的访问
应用场景
远程代理，也就是为了一个对象在不同的地址空间提供局部代表。这样可以隐藏一个对象存在于不同的地址空间的事实
虚拟代理，是根据需要创建开销很大的对象。通过它来存放实例化需要很长时间的真实对象
安全代理，用来控制真实对象的访问权限
智能指针，是指当调用真实的对象时，代理处理另外一些事。例如智能指针计算真实对象的引用次数，这样当对象没有引用时，可以自动释放它

eg:本例描述一个追求者pursuit想要追一个女孩SchoolGirl，可是不好意思送给她，所以就找代理proxy
定义一个基类IGiveGift，里面有送娃娃和送鲜花的方法
追求者pursuit和代理proxy继承基类实现里面的方法
main函数中我们用proxy去代理送礼物，这样女生也不知道这个代理是替谁送礼物，因为已经封装在proxy里面了
*/
#include<iostream>
#include"proxy.h"
using namespace std;
int main(){
	SchoolGirl* girl = new SchoolGirl();
	girl->setName("ss");
	Proxy* proxy = new Proxy(girl);
	proxy->GiveDolls();
	proxy->GiveFlowers();
}

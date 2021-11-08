/*The singleton pattern ensures that a class has only one instance and provides a global point of access to
that instance. 一个类只能实例化一个对象

eg: 将构造函数和指向Singleton实例的指针_instance设置为private
当客户端调用getInstance时，判断_instance是否已经指向一个实例
*/
#include <iostream>
using namespace std;
class Singleton{
public:
    static Singleton* getInstance() {
        if(_instance==0) {
            _instance = new Singleton();
        }
        return _instance;
    }
private:
    static Singleton* _instance;  //下划线通常用来表示变量是实例变量
    Singleton() {
        cout<<"singleton..."<<endl;
    }
};
Singleton* Singleton::_instance = 0; //C++ standard allows only static constant integral or enumeration types to be initialized inside the class
int main() {
    Singleton* sgln1 = Singleton::getInstance();
    Singleton* sgln2 = Singleton::getInstance();  //这个就创建不了
    delete sgln1;
    //delete sgln2;  //sgln1 share the same point with sgln2, so deleting 2 will make error.
}
/*factory模式是为一类对象提供创建接口。而abstractfactory 是为多类（一组）相关或依赖对象提供创建接口。

eg：本例通过后台切换数据库来展示工厂模式 因为在使用是数据库时，应该会因为需求而切换不同的数据库，
例子中是后台对sqlserver和mysql数据库的切换
1.抽象出所有操作的基础类IUser,IDepartment
2.针对基础类定义接口。
3.基础类IUser的接口函数insert()，getUser()。
4.基础类IDepartment的接口函数insert()，getDepartment()
5.数据库MysqlUser，SqlserverUser继承基础类IUser，数据库MysqlDepartment，SqlserverDeparment继承
基础类IDepartment来实现接口
6.基础类抽象工厂类Factory来定义接口来实例化不同的数据库
7.SqlserverFactory和MysqlFactory继承Factory实现接口
8.这样就可以通过声明一个指向基类Factory的指针来指向实际的子类SqlserverFactory和MysqlFactory实现,
达到自由切换数据库的目的
*/
#include <iostream>
#include <string>
using namespace std;

class IUser{
public:
    virtual void insert() = 0;
    virtual void getUser() = 0;
    virtual ~IUser(){}
};

class SqlseverUser:public IUser {
public:
    virtual void insert() {
        cout<<"Insert user data into sqlsever."<<endl;
    }
    virtual void getUser() {
        cout<<"Get user information from sqlsever."<<endl;
    }
    virtual ~SqlseverUser(){

    }
};

class MysqlUser:public IUser {
public:
    virtual void insert() {
        cout<<"Insert user data into mysql."<<endl;
    }
    virtual void getUser() {
        cout<<"Get user information from mysql."<<endl;
    }
    virtual ~MysqlUser(){
        
    }
};

class IDepartment{
public:
    virtual void insert() = 0;
    virtual void getDepartment() = 0;
    virtual ~IDepartment(){}
};

class SqlseverDepartment :public IDepartment {
public:
    virtual void insert() {
        cout<<"Insert department information into sqlsever."<<endl;
    }
    virtual void getDepartment() {
        cout<<"Get department information from sqlsever."<<endl;
    }
    virtual ~SqlseverDepartment(){

    }
};

class MysqlDepartment :public IDepartment {
public:
    virtual void insert() {
        cout<<"Insert department information into mysql."<<endl;
    }
    virtual void getDepartment() {
        cout<<"Get department information from mysql."<<endl;
    }
    virtual ~MysqlDepartment(){

    }
};

class Factory{
public:
    void factoryPrint() {
        cout<<"factory"<<endl;
    }
    virtual IUser* createUser() = 0;
    virtual IDepartment* createDepartment() = 0;
    virtual ~Factory() {}
};

class SqlseverFactory: public Factory {
public:
    virtual IUser* createUser() {
        return new SqlseverUser();
    }
    virtual IDepartment* createDepartment() {
        return new SqlseverDepartment();
    }
    virtual ~SqlseverFactory() {

    }
};

class MysqlFactory: public Factory {
public:
    virtual IUser* createUser() {
        return new MysqlUser();
    }
    virtual IDepartment* createDepartment() {
        return new MysqlDepartment();
    }
    virtual ~MysqlFactory() {
   
    }
};

int main() {
    Factory* factory = new SqlseverFactory();
    IUser* iu = factory->createUser();
    iu->insert();
    iu->getUser();

    IDepartment* id = factory->createDepartment();
    id->insert();
    id->getDepartment();

    delete iu;
    delete factory;
    delete id;
}
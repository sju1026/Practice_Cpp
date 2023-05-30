#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#pragma region RealObjUnder1
class Data {
private:
    int data;
public:
    Data(int num) : data(num){}
    void ShowData() { cout << "Data: " << data << endl; }
    void Add(int num) { data += num; }
};
#pragma endregion

#pragma region RealObjUnder2
typedef struct Data1 {
    int data;
    void (*ShowData)(Data1*);
    void (*Add)(Data1*, int);
}Data1;

void ShowData(Data1* THIS) { cout << "Data: " << THIS->data << endl; }
void Add(Data1* THIS, int num) { THIS->data += num; }
#pragma endregion

#pragma region VirtualInternal
class AAA {
private:
    int num1;
public:
    virtual void Func1() { cout << "Func1" << endl; }
    virtual void Func2() { cout << "Func2" << endl; }
};

class BBB : public AAA {
private:
    int num2;
public:
    virtual void Func1() { cout << "BBB::Func1" << endl; }
    void Func3() { cout << "Func3" << endl; }
};
#pragma endregion

#pragma region MultiInheri1
class BaseOne {
public:
    void SimpleFuncOne() { cout << "BaseOne" << endl; }
};

class BaseTwo {
public:
    void SimpleFuncTwo() { cout << "BaseTwo" << endl; }
};

class MultiDerived : public BaseOne, protected BaseTwo {
public:
    void ComplexFunc() {
        BaseOne::SimpleFuncOne();
        BaseTwo::SimpleFuncTwo();
    }
};
#pragma endregion

#pragma region MultiInheri3
class Base {
public:
    Base() { cout << "Base Constructor" << endl; }
    void SimpleFunc() { cout << "BaseOne" << endl; }
};

class MiddleDerivedOne : virtual public Base {
public:
    MiddleDerivedOne() : Base() {
        cout << "MiddleDerivedOne Constructor" << endl;
    }
    void MiddleFuncOne() {
        SimpleFunc();
        cout << "MiddleDerivedOne" << endl;
    }
};

class MiddleDerivedTwo : virtual public Base {
public:
    MiddleDerivedTwo() : Base() {
        cout << "MiddleDerivedTwo Constructor" << endl;
    }
    void MiddleFuncTwo() {
        SimpleFunc();
        cout << "MiddleDerivedTwo" << endl;
    }
}; 

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo {
public:
    LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo() {
        cout << "LastDerived Constructor" << endl;
    }
    void ComplexFunc() {
        MiddleFuncOne();
        MiddleFuncTwo();
        SimpleFunc();
    }
};
#pragma endregion



int main(void)
{
    /*Data obj(15);
    obj.Add(17);
    obj.ShowData();*/

    /*Data1 obj1 = { 15, ShowData, Add };
    Data1 obj2 = { 7, ShowData, Add };

    obj1.Add(&obj1, 17);
    obj2.Add(&obj2, 9);
    obj1.ShowData(&obj1);
    obj2.ShowData(&obj2);*/

    /*AAA* aptr = new AAA();
    aptr->Func1();

    BBB* bptr = new BBB();
    bptr->Func1();*/

    /*MultiDerived mdr;
    mdr.ComplexFunc();*/
    
    cout << "객체생성 전 ...." << endl;
    LastDerived ldr;
    cout << "객체생성 후 ...." << endl;
    ldr.ComplexFunc();

    return 0;
}


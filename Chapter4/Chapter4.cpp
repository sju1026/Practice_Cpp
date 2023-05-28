#include <iostream>
#include <cstring>
#include "Point.h"
#include "Rectangle.h"
#pragma warning(disable:4996)

using namespace std;

#pragma region Encapsulatino
class SinivelCap {
public:
    void Take() const { cout << "콧물이 싹~ 납니다." << endl; }
};

class SneezeCap {
public:
    void Take() const { cout << "재채기가 멎습니다." << endl; }
};

class SnuffleCap {
public:
    void Take() const { cout << "코가 뻥 뚫립니다." << endl; }
};

//class ColdPatient {
//public:
//    void TakeSinivelCap(const SinivelCap& cap) const { cap.Take(); }
//    void TakeSneezeCap(const SneezeCap& cap) const { cap.Take(); }
//    void TakeSnuffleCap(const SnuffleCap& cap) const { cap.Take(); }
//};

class CONTAC600 {
private:
    SinivelCap sin;
    SneezeCap sne;
    SnuffleCap snu;
public:
    void Take() const {
        sin.Take();
        sne.Take();
        snu.Take();
    }
};

class ColdPatient {
public:
    void TakeCONTAC600(const CONTAC600& cap) const { cap.Take(); }
};
#pragma endregion

#pragma region Constructor/Destructor
class SimpleClass {
private:
    int num1;
    int num2;
public:
    /*SimpleClass() {
        num1 = 0;
        num2 = 0;
    }
    SimpleClass(int n) {
        num1 = n;
        num2 = 0;
    }
    SimpleClass(int n1, int n2) {
        num1 = n1;
        num2 = n2;
    }*/
    SimpleClass(int n1 = 0, int n2 = 0) {
        num1 = n1;
        num2 = n2;
    }

    void ShowData() const {
        cout << num1 << ' ' << num2 << endl;
    }
};

// ReferneceMember
class AAA {
public:
    AAA() {
        cout << "empty object" << endl;
    }
    void ShowYorName() {
        cout << "I'm class AAA" << endl;
    }
};

class BBB {
private:
    AAA& ref;
    const int& num;
public:
    BBB(AAA &r, const int &n)
        :ref(r), num(n) 
    {
    }
    void ShowYourName() {
        ref.ShowYorName();
        cout << "and" << endl;
        cout << "I'm ref num" << num << endl;
    }
};

//Default Constructure
class AAA1 {
private:
    int num;
public:
    AAA1() :num(0){}
    AAA1& CreateInitObj(int n) const {
        AAA1* ptr = new AAA1(n);
        return *ptr;
    }
    void ShowNum() const { cout << num << endl; }
private:
    AAA1(int n) : num(0) {}
};
#pragma endregion

#pragma region Pointer
class Person {
private:
    char* name;
    int age;
public:
    Person(const char* myname, int myage) {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    Person() {
        name = NULL;
        age = 0;
        cout << "called Person()" << endl;
    }
    void SetPersonInfo(char* myname, int myage) {
        name = myname;
        age = myage;
    }
    void ShowPersonInfo() const {
        cout << "이름: " << name << ',';
        cout << "나이: " << age << endl;
    }
    ~Person() {
        delete[]name;
        cout << "called destructor!" << endl;
    }
};

// this 포인터의 이해
class SoSimple {
private:
    int num;
public:
    SoSimple(int n) : num(n) {
        cout << "num=" << num << ", ";
        cout << "address=" << this << endl;
    }
    void SowSimpleData() {
        cout << num << endl;
    }
    SoSimple* GetThisPointer() {
        return this;
    }
};

// this 포인터 활용
class TwoNumber {
private:
    int num1;
    int num2;
public:
    TwoNumber(int num1, int num2) {
        this->num1 = num1;
        this->num2 = num2;
    }
    void ShowTwoNumber() {
        cout << this->num1 << endl;
        cout << this->num2 << endl;
    }
};

// Self-Reference의 반환
class SelfRef {
private:
    int num;
public:
    SelfRef(int n) : num(n) {
        cout << "객체 생성" << endl;
    }
    SelfRef& Adder(int n) {
        num += n;
        return *this;
    }
    SelfRef& ShowTwoNumber() {
        cout << num << endl;
        return *this;
    }
};
#pragma endregion

int main(void)
{
    /*Rectangle rec(1, 1, 5, 5);
    rec.ShowRecInfo();*/

    /*SinivelCap scap;
    SneezeCap zcap;
    SnuffleCap ncap;

    ColdPatient sufferer;
    sufferer.TakeSinivelCap(scap);
    sufferer.TakeSneezeCap(zcap);
    sufferer.TakeSnuffleCap(ncap);

    CONTAC600 cap;
    ColdPatient sufferer;
    sufferer.TakeCONTAC600(cap);*/

    /*SimpleClass sc1;
    sc1.ShowData();

    SimpleClass sc2(100);
    sc2.ShowData();

    SimpleClass sc3(100, 200);
    sc3.ShowData();*/

    /*SimpleClass sc1();
    SimpleClass mysc = sc1();
    mysc.ShowData();*/

    /*AAA obj1;
    BBB obj2(obj1, 20);
    obj2.ShowYourName();*/

    /*AAA1 base;
    base.ShowNum();

    AAA1& obj1 = base.CreateInitObj(3);
    obj1.ShowNum();

    AAA1& obj2 = base.CreateInitObj(12);
    obj2.ShowNum();

    delete& obj1;
    delete& obj2;*/

    /*Person man1("Lee dong woo", 29);
    Person man2("Jang dong gun", 41);
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();*/

    // 객체 배열
    /*Person parr[3];
    char namestr[100];
    char* strptr;
    int age;
    int len;

    for (int  i = 0; i < 3; i++)
    {
        cout << "이름: ";
        cin >> namestr;
        cout << "나이: ";
        cin >> age;
        len = strlen(namestr) + 1;
        strptr = new char[len];
        strcpy(strptr, namestr);
        parr[i].SetPersonInfo(strptr, age);
    }
    parr[0].ShowPersonInfo();
    parr[1].ShowPersonInfo();
    parr[2].ShowPersonInfo();*/

    // 객체 포인터 배열
    /*Person* parr[3];
    char namestr[100];
    int age;

    for (int i = 0; i < 3; i++)
    {
        cout << "이름: ";
        cin >> namestr;
        cout << "나이: ";
        cin >> age;
        parr[i] = new Person(namestr, age);
    }
    parr[0]->ShowPersonInfo();
    parr[1]->ShowPersonInfo();
    parr[2]->ShowPersonInfo();
    delete parr[0];
    delete parr[1];
    delete parr[2];*/

    // this 포인터 이해
    /*SoSimple sim1(100);
    SoSimple* ptr1 = sim1.GetThisPointer();
    cout << ptr1 << ", ";
    ptr1->SowSimpleData();

    SoSimple sim2(200);
    SoSimple* ptr2 = sim2.GetThisPointer();
    cout << ptr2 << ", ";
    ptr2->SowSimpleData();*/
    
    // this 포인터 활용
    //TwoNumber two(2, 4);
    //two.ShowTwoNumber();

    SelfRef obj(3);
    SelfRef& ref = obj.Adder(2);

    obj.ShowTwoNumber();
    ref.ShowTwoNumber();

    ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
    return 0;
}

SimpleClass sc1() {
    SimpleClass sc(20, 30);
    return sc;
}

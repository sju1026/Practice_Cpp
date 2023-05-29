#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#pragma region ClassInit
class SoSimple {
private:
    int num1;
    int num2;
public:
    SoSimple(int n1, int n2)
        : num1(n1), num2(n2) {
    }
    SoSimple(SoSimple& copy)
        : num1(copy.num1), num2(copy.num2) {
        cout << "Called SoSimple(SoSimple &copy)" << endl;
    }
    void ShowSimpleData() {
        cout << num1 << endl;
        cout << num2 << endl;
    }
};
#pragma endregion

#pragma region ShallowCopyError
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
    void ShowPersonInfo() const {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
    ~Person() {
        delete[]name;
        cout << "called destructor!" << endl;
    }
};
#pragma endregion

#pragma region PassObjCopycon
class SoSimple1 {
private:
    int num;
public:
    SoSimple1(int n) : num(n) {}
    SoSimple1(const SoSimple1& copy) : num(copy.num) {
        cout << "Called SoSimple1(const SoSimple & copy)" << endl;
    }
    void ShowData() {
        cout << "num: " << num << endl;
    }
};

void SimpleFunObj(SoSimple1 ob) {
    ob.ShowData();
}
#pragma endregion

#pragma region ReturnObjCopycon
class SoSimple2 {
private:
    int num;
public:
    SoSimple2(int n) : num(n)
    { }
    SoSimple2(const SoSimple2& copy) : num(copy.num) {
        cout << "Called SoSimple2(const SoSimple2& copy)" << endl;
    }
    SoSimple2& AddNum(int n) {
        num += n;
        return *this;
    }
    void ShowData() {
        cout << "num: " << num << endl;
    }
};

SoSimple2 Simple2FuncObj(SoSimple2 ob) {
    cout << "return 이전" << endl;
    return ob;
}
#pragma endregion

#pragma region IKnowTempObj
class Temporary {
private:
    int num;
public:
    Temporary(int n) : num(n){
        cout << "create obj: " << num << endl;
    }
    ~Temporary() {
        cout << "destroy obj: " << num << endl;
    }
    void ShowTempInfo() {
        cout << "My num is" << num << endl;
    }
};
#pragma endregion

#pragma region ReturnObjDeadTime
class SoSimple3 {
private:
    int num;
public:
    SoSimple3(int n) : num(n) {
        cout << "New Object: " << this << endl;
    }
    SoSimple3(const SoSimple3& copy) : num(copy.num) {
        cout << "New Copy obj: " << this << endl;
    }
    ~SoSimple3() {
        cout << "Destroy obj: " << this << endl;
    }
};

SoSimple3 Simple3FuncObj(SoSimple3 ob) {
    cout << "Parm ADR: " << &ob << endl;
    return ob;
}
#pragma endregion

#pragma region BankingSystemVer03
class Account {
private:
    int accID;
    int balance;
    char* cusName;
public:
    Account(int ID, int money, char* name) : accID(ID), balance(money), cusName(name) {
        cusName = new char[strlen(name) + 1];
        strcpy(cusName, name);
    }
    Account(const Account& ref) : accID(ref.accID), balance(ref.balance){
        cusName = new char[strlen(ref.cusName) + 1];
        strcpy(cusName, ref.cusName);
    }

    int GetAccID() const { return accID; };

    void Deposit(int money) {
        balance += money;
    }

    int Withdraw(int money) {
        if (balance<money)
        {
            return 0;
        }
        balance -= money;
        return money;
    }

    void ShowAccInfo() const {
        cout << "계좌 ID: " << accID << endl;
        cout << "이 름: " << cusName << endl;
        cout << "잔 액: " << balance << endl;
    }

    ~Account() {
        delete[]cusName;
    }
};
#pragma endregion


int main()
{
    // ClassInit
    /*SoSimple sim1(15, 30);
    cout << "생성 및 초기화 직전" << endl;
    SoSimple sim2 = sim1;
    cout << "생성 및 초기화 직후" << endl;
    sim2.ShowSimpleData();*/

    // ShallowCopyError
    /*Person man1("Lee dong woo", 29);
    Person man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();*/

    // PassObjCopycon
    /*SoSimple1 obj(7);
    cout << "함수호출 전" << endl;
    SimpleFunObj(obj);
    cout << "함수호출 후" << endl;*/

    // ReturnObjCopycon
    /*SoSimple2 obj(7);
    Simple2FuncObj(obj).AddNum(30).ShowData();
    obj.ShowData();*/

    // IKnowTempObj
    /*Temporary(100);
    cout << "********** after make!" << endl << endl;
    Temporary(200).ShowTempInfo();
    cout << "********** after make!" << endl << endl;
    const Temporary& ref = Temporary(300);
    cout << "********** end of main!" << endl << endl;*/

    // ReturnObjDeadTime
    /*SoSimple3 obj(7);
    Simple3FuncObj(obj);

    cout << endl;
    SoSimple3 tempRef = Simple3FuncObj(obj);
    cout << "Return obj " << &tempRef << endl;*/

    // BankingSystemVer03
    return 0;
}

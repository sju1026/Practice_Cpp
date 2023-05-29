#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#pragma region EmployeeManager
class PermanentWorker {
private:
    char name[100];
    int salary;
public:
    PermanentWorker(const char* name, int money) :salary(money) {
        strcpy(this->name, name);
    }
    int GetPay() const {
        return salary;
    }
    void ShowSalaryInfo() const {
        cout << "anme: " << name << endl;
        cout << "salary: " << GetPay() << endl << endl;
    }
};

class EmployeeHandler {
private:
    PermanentWorker* empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0) {}
    void AddEmployee(PermanentWorker* emp) {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }
    void ShowTotalSalary() const {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }
    ~EmployeeHandler() {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};
#pragma endregion

#pragma region UnivStudentInheri
class Person {
private:
    int age;
    char name[50];
public:
    Person(int myage,const char* myname) : age(myage) {
        strcpy(name, myname);
    }
    void WhatYourNmae() const {
        cout << "My name is " << name << endl;
    }
    void HowOldAreYou() const {
        cout << "I'm " << age << " years old" << endl;
    }   
};

class UnivStudent : public Person {
private:
    char major[50];
public:
    UnivStudent(const char* myname, int myage, const char* mymajor) :Person(myage, myname) {
        strcpy(major, mymajor);
    }
    void WhoArYou() const {
        WhatYourNmae();
        HowOldAreYou();
        cout << "My major is " << major << endl << endl;
    }
};
#pragma endregion

#pragma region DerivCreOrder
class SoBase {
private:
    int baseNum;
public:
    SoBase() : baseNum(20) {
        cout << "SoBase()" << endl;
    }
    SoBase(int n) : baseNum(n) {
        cout << "SoBase(int n)" << endl;
    }
    void ShowBaseData() {
        cout << baseNum << endl;
    }
};

class SoDerived :public SoBase {
private:
    int derivNum;
public:
    SoDerived() : derivNum(30) {
        cout << "SoDerived()" << endl;
    }
    SoDerived(int n) : derivNum(n) {
        cout << "SoDerived(int n)" << endl;
    }
    SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2) {
        cout << "SoDerived(int n1, int n2)" << endl;
    }
    void ShowDerivData() {
        ShowBaseData();
        cout << derivNum << endl;
    }
};
#pragma endregion

#pragma region DrivDestOrder
class SoBase1 {
private:
    int baseNum;
public:
    SoBase1(int n) : baseNum(n) {
        cout << "SoBase() : " << baseNum << endl;
    }
    ~SoBase1() {
        cout << "~SoBase() : " << baseNum << endl;
    }
};

class SoDerived1 : public SoBase1 {
private:
    int derivNum;
public:
    SoDerived1(int n) : SoBase1(n), derivNum(n) {
        cout << "SoDerived() : " << derivNum << endl;
    }
    ~SoDerived1() {
        cout << "~SoDerived() : " << derivNum << endl;
    }
};
#pragma endregion

#pragma region DestModel
class Person1 {
private:
    char* name;
public:
    Person1(const char* myname) {
        name = new char[strlen(myname) + 1];
        strcpy(name, myname);
    }
    ~Person1() {
        delete[]name;
    }
    void WharYourName() const {
        cout << "My Name is " << name << endl;
    }
};

class UnivStudent1 : public Person1 {
private:
    char* major;
public:
    UnivStudent1(const char* myname, const char* mymajor) :Person1(myname) {
        major = new char[strlen(mymajor) + 1];
        strcpy(major, mymajor);
    }
    ~UnivStudent1() {
        delete[]major;
    }
    void WhoArYou() const {
        WharYourName();
        cout << "My major is " << major << endl << endl;
    }
};
#pragma endregion

#pragma region ProtectedHeri
class Base {
private:
    int num1;
protected:
    int num2;
public:
    int num3;
    Base():num1(1), num2(2), num3(3){}
};

class Derived : public Base {};
#pragma endregion

#pragma region ISAInheritance
class Computer {
private:
    char owner[50];
public:
    Computer(const char* name) {
        strcpy(owner, name);
    }
    void Calculate() {
        cout << "요청 내용을 계산합니다." << endl;
    }
};

class NotebookComp : public Computer {
private:
    int Battery;
public:
    NotebookComp(const char * name, int initChag): Computer(name), Battery(initChag){}
    void Charging() { Battery += 5; }
    void UseBattery() { Battery -= 1; }
    void MovingCal() {
        if (GetBatteryInfo()<1)
        {
            cout << "충전이 필요하빈다." << endl;
            return;
        }
        cout << "이동하면서 ";
        Calculate();
        UseBattery();
    }
    int GetBatteryInfo() { return Battery; }
};

class TabletNotebook : public NotebookComp {
private:
    char regstPenModel[50];
public:
    TabletNotebook(const char* name, int initChag, const char* pen) :NotebookComp(name, initChag) {
        strcpy(regstPenModel, pen);
    }
    void Write(const char* penInfo) {
        if (GetBatteryInfo()<1)
        {
            cout << "충전이 필요합니다." << endl;
            return;
        }
        if (strcmp(regstPenModel, penInfo)!=0)
        {
            cout << "등록된 펜이 아닙니다.";
            return;
        }
        cout << "필기 내용을 처리합니다." << endl;
        UseBattery();
    }
};
#pragma endregion

#pragma region HASInheritance
class Gun {
private:
    int bullet;
public:
    Gun(int bnum) : bullet(bnum) {}
    void Shot() {
        cout << "BBANG!" << endl;
        bullet--;
    }
};

//class Police : public Gun {
//private:
//    int handCuffs;
//public:
//    Police(int bnum, int bcuff) : Gun(bnum), handCuffs(bcuff){}
//    void PutHandcuff() {
//        cout << "SNAP!" << endl;
//        handCuffs--;
//    }
//};

class Police {
private:
    int handcuffs;
    Gun* pistol;
public:
    Police(int bnum, int bcuff) : handcuffs(bcuff) {
        if (bnum > 0)
            pistol = new Gun(bnum);
        else
            pistol = NULL;
    }
    void PutHandcuff() {
        cout << "SNAP!" << endl;
        handcuffs--;
    }
    void Shot() {
        if (pistol == NULL)
            cout << "Hut BBANG!" << endl;
        else
            pistol->Shot();
    }
    ~Police() {
        if (pistol != NULL)
            delete pistol;
    }
};
#pragma endregion




int main(void)
{
    // EmployeeManager
    /*EmployeeHandler handler;

    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    handler.AddEmployee(new PermanentWorker("JUN", 2000));

    handler.ShowAllSalaryInfo();

    handler.ShowTotalSalary();*/

    // UnivStudentInheri
    /*UnivStudent ustd1("Lee", 22, "Computer eng.");
    ustd1.WhoArYou();

    UnivStudent ustd2("Yoon", 21, "Electronic eng.");
    ustd2.WhoArYou();*/

    // DerivCreOrder
    /*cout << "case1....." << endl;
    SoDerived dr1;
    dr1.ShowDerivData();
    cout << "-----------------------" << endl;
    cout << "case2....." << endl;
    SoDerived dr2(12);
    dr2.ShowDerivData();
    cout << "-----------------------" << endl;
    cout << "case3....." << endl;
    SoDerived dr3(23, 24);
    dr3.ShowDerivData();
    cout << "-----------------------" << endl;*/

    // DrivDestOrder
    /*SoDerived1 drv1(15);
    SoDerived1 drv2(27);*/

    // DestModel
    /*UnivStudent1 st1("Kim", "Mathematics");
    st1.WhoArYou();
    UnivStudent1 st2("Hong", "Physics");*/

    // ProtectedHeri
    /*Derived drv;
    cout << drv.num3 << endl;*/

    /*NotebookComp nc("이수종", 5);
    TabletNotebook tn("정수영", 5, "ISE-241-242");
    nc.MovingCal();
    tn.Write("ISE-241-242");*/

    // HASInheritance
    /*Police pman(5, 3);
    pman.Shot();
    pman.PutHandcuff();*/
    Police pman1(5, 3);
    pman1.Shot();
    pman1.PutHandcuff();

    Police pman2(0, 3);
    pman2.Shot();
    pman2.PutHandcuff();

    return 0;
}


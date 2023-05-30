#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#pragma region ObjectPointer
class Person {
public:
    void Sleep() { cout << "Sleep" << endl; }
};

class Student : public Person {
public:
    void Study() { cout << "Study" << endl; }
};

class PartTimeStudent : public Student {
public:
    void Work() { cout << "Work" << endl; }
};
#pragma endregion

#pragma region EmployeeManager2,3
class Employee {
private:
    char name[100];
public:
    Employee(const char* name) {
        strcpy(this->name, name);
    }
    void ShowYourName() const {
        cout << "name: " << name << endl;
    }
    virtual int GetPay() const {
        return 0;
    }
    virtual void ShowSalaryInfo() const {
    }
};

class PermanentWorker : public Employee {
private:
    int salary;
public:
    PermanentWorker(const char * name, int money) : Employee(name), salary(money){}
    int GetPay() const {
        return salary;
    }
    void ShowSalaryInfo() const {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

class TemporaryWorker : public Employee {
private:
    int workTime;
    int payPerHour;
public:
    TemporaryWorker(const char* name, int pay) : Employee(name), workTime(0), payPerHour(pay) {}
    void AddWorkTime(int time) {
        workTime += time;
    }
    int GetPay() const {
        return workTime * payPerHour;
    }
    void ShowSalaryInfo() const {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

class SalesWorker : public PermanentWorker {
private:
    int salesResult;
    double bonusRatio;
public:
    SalesWorker(const char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}
    void AddSalesResult(int value) {
        salesResult += value;
    }
    int GetPay() const {
        return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
    }
    void ShowSalaryInfo() const {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

class EmployeeHandler {
private:
    Employee* empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0){}
    void AddEmployee(Employee* emp) {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const {
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

#pragma region FunctionOverride
class First {
public:
    void MyFunc() { cout << "FirstFunc" << endl; }
};

class Second : public First {
public:
    void MyFunc() { cout << "SecondFunc" << endl; }
};

class Third : public Second {
public:
    void MyFunc() { cout << "ThirdFunc" << endl; }
};
#pragma endregion

#pragma region FunctionVirtualOverride
class First1 {
public:
    virtual void MyFunc() { cout << "First1Func" << endl; }
};

class Second1 : public First1 {
public:
    virtual void MyFunc() { cout << "Second1Func" << endl; }
};

class Third1 : public Second1 {
public:
    virtual void MyFunc() { cout << "Third1Func" << endl; }
};
#pragma endregion

#pragma region VirtualDestructor
class First2 {
private:
    char* strOne;
public:
    First2(const char* str) {
        strOne = new char[strlen(str) + 1];
    }
    ~First2() {
        cout << "~First()" << endl;
        delete[] strOne;
    }
};

class Second2 : public First2 {
private:
    char* strTwo;
public:
    Second2(const char* str1, const char* str2) : First2(str1) {
        strTwo = new char[strlen(str2) + 1];
    }
    ~Second2() {
        cout << "~Second()" << endl;
        delete[] strTwo;
    }
};
#pragma endregion

#pragma region ReferenceAttribute
class First3 {
public : 
    void First3Func() { cout << "First3Func()" << endl; }
    virtual void SimpleFunc() { cout << "Frist3's SimpleFunc()" << endl; }
};

class Second3 : public First3 {
public:
    void Second3Func() { cout << "Second3Func()" << endl; }
    virtual void SimpleFunc() { cout << "Second3's SimpleFunc()" << endl; }
};

class Third3 : public Second3 {
public:
    void Third3Func() { cout << "Third3Func()" << endl; }
    virtual void SimpleFunc() { cout << "Third3's SimpleFunc()" << endl; }
};
#pragma endregion

int main()
{
    // ObjectPointer
    /*Person* ptr1 = new Student();
    Person* ptr2 = new PartTimeStudent();
    Student* ptr3 = new PartTimeStudent();
    ptr1->Sleep();
    ptr2->Sleep();
    ptr3->Study();
    delete ptr1; delete ptr2; delete ptr3;*/

    // EmployeeManager2
    /*EmployeeHandler handler;
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    handler.AddEmployee(new PermanentWorker("JUN", 2000));

    TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);
    
    SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);

    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();*/

    // FunctionOverride
    /*Third* tptr = new Third();
    Second* sptr = new Second();
    First* fptr = new First();*/
    /*Third1* tptr = new Third1();
    Second1* sptr = tptr;
    First1* fptr = sptr;

    fptr->MyFunc();
    sptr->MyFunc();
    tptr->MyFunc();
    delete tptr;*/

    // VirtualDestructor
    /*First2* ptr = new Second2("simple", "complex");
    delete ptr;*/

    // ReferenceAttribute
    Third3 obj;
    obj.First3Func();
    obj.Second3Func();
    obj.Third3Func();
    obj.SimpleFunc();

    Second3& sref = obj;
    sref.First3Func();
    sref.Second3Func();
    sref.SimpleFunc();

    Third3& fref = obj;
    fref.First3Func();
    fref.SimpleFunc();

    return 0;
}

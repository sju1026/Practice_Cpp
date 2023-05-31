#include <iostream>
#include <cstring>
#include <cstdlib>
#pragma warning(disable:4996)
using namespace std;

#pragma region FirstOperationOverloading
class First {
private:
    int num1, num2;
public:
    First(int n1=0, int n2=0) : num1(n1), num2(n2){}
    void ShowData() { cout << num1 << ", " << num2 << endl; }
};

class Second {
private:
    int num3, num4;
public:
    Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4) {}
    void ShowData() { cout << num3 << ", " << num4 << endl; }

    Second& operator=(const Second& ref) {
        cout << "Second& operator=()" << endl;
        num3 = ref.num3;
        num4 = ref.num4;
        return *this;
    }
};
#pragma endregion

#pragma region AssignShallowCopyError
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
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
    }
    ~Person() {
        delete[]name;
        cout << "called destructor!" << endl;
    }
};
#pragma endregion

#pragma region InheritAssignOperation
class First1 {
private:
    int num1, num2;
public:
    First1(int n1 = 0, int n2 = 0) : num1(n1), num2(n2) { }
    void ShowData() { cout << num1 << ", " << num2 << endl; }

    First1& operator=(const First1& ref) {
        cout << "First1& operator=()" << endl;
        num1 = ref.num1;
        num2 = ref.num2;
        return *this;
    }
};

class Second1 : public First1 {
private:
    int num3, num4;
public:
    Second1(int n1, int n2, int n3, int n4) : First1(n1, n2), num3(n3), num4(n4) { }
    void ShowData() {
        First1::ShowData();
        cout << num3 << ", " << num4 << endl;
    }
    Second1& operator=(const Second1& ref) {
        cout << "Second1& operator=()" << endl;
        num3 = ref.num3;
        num4 = ref.num4;
        return *this;
    }
};
#pragma endregion

#pragma region ImproveInit
class AAA {
private:
    int num;
public:
    AAA(int n = 0) : num(n) {
        cout << "AAA(int n=0)" << endl;
    }
    AAA(const AAA& ref) : num(ref.num) {
        cout << "AAA(const AAA& ref)" << endl;
    }
    AAA& operator=(const AAA& ref) {
        num = ref.num;
        cout << "operator=(const AAA& ref)" << endl;
        return *this;
    }
};

class BBB {
private:
    AAA mem;
public:
    BBB(const AAA& ref) : mem(ref) { }
};

class CCC {
private:
    AAA mem;
public:
    CCC(const AAA& ref) { mem = ref; }
};
#pragma endregion

#pragma region ArrayClass
class Point {
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
    friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos) {
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

typedef Point* POINT_PTR;

class BoundChectIntArray {
private:
    POINT_PTR* arr;
    int arrlen;

    BoundChectIntArray(const BoundChectIntArray& arr) { }
    BoundChectIntArray& operator=(const BoundChectIntArray& arr) { }
public:
    BoundChectIntArray(int len) : arrlen(len) {
        arr = new POINT_PTR[len];
    }
    POINT_PTR& operator[] (int idx) {
        if (idx<0 || idx>=arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    POINT_PTR operator[] (int idx) const {
        if (idx<0 || idx>=arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    int GetArrLen() const { return arrlen; }
    ~BoundChectIntArray() { delete[]arr; }
};
//
//void ShowAllData(const BoundChectIntArray& ref) {
//    int len = ref.GetArrLen();
//    for (int idx = 0; idx < len; idx++)
//        cout << ref[idx] << endl;
//}
#pragma endregion

#pragma region NewDeleteOverloading
class Point1 {
private:
    int xpos, ypos;
public:
    Point1(int x = 0, int y = 0) : xpos(x), ypos(y) { }
    friend ostream& operator<<(ostream& os, const Point1& pos);

    void* operator new (size_t size) {
        cout << "operator new : " << size << endl;
        void* adr = new char[size];
        return adr;
    }

    void* operator new[](size_t size) {
        cout << "operator new [] : " << size << endl;
        void* adr = new char[size];
        return adr;
    }

    void operator delete (void* adr) {
        cout << "operator delete ()" << endl;
        delete[]adr;
    }

    void operator delete[] (void* adr) {
        cout << "operator delete[] ()" << endl;
        delete[]adr;
    }
};

ostream& operator<<(ostream& os, const Point1& pos) {
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}
#pragma endregion

#pragma region PointerOperatorOverloading
class Number {
private:
    int num;
public:
    Number(int n) : num(n) {}
    void ShowData() { cout << num << endl; }

    Number* operator->() {
        return this;
    }

    Number& operator*() {
        return *this;
    }
};
#pragma endregion

#pragma region SmartPointer
class Pointer {
private:
    int xpos, ypos;
public:
    Pointer(int x = 0, int y = 0) : xpos(x), ypos(y) {
        cout << "Pointer 객체 생성" << endl;
    }
    ~Pointer() {
        cout << "Pointer 객체 소멸" << endl;
    }
    void SetPos(int x, int y) {
        xpos = x;
        ypos = y;
    }
    friend ostream& operator<<(ostream& os, const Pointer& pos);
};

ostream& operator<<(ostream& os, const Pointer& pos) {
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

class SmartPtr {
private:
    Pointer* posptr;
public:
    SmartPtr(Pointer* ptr) : posptr(ptr) { }
    Pointer& operator*() const {
        return *posptr;
    }
    Pointer* operator->() const {
        return posptr;
    }
    ~SmartPtr() {
        delete posptr;
    }
};
#pragma endregion

#pragma region SortFunctor
class SortRule {
public:
    virtual bool operator() (int num1, int num2) const = 0;
};

class AscendingSort : public SortRule {
public:
    bool operator() (int num1, int num2) const{
        if (num1 > num2)
            return true;
        else
            return false;
    }
};

class DescendingSort : public SortRule {
public:
    bool operator() (int num1, int num2) const {
        if (num1 < num2)
            return true;
        else
            return false;
    }
};

class DataStorage {
private:
    int* arr;
    int idx;
    const int MAX_LEN;
public:
    DataStorage(int arrlen) : idx(0), MAX_LEN(arrlen) {
        arr = new int[MAX_LEN];
    }
    void AddData(int num) {
        if (MAX_LEN <= idx) {
            cout << "더 이상 저장이 불가능합니다." << endl;
            return;
        }
        arr[idx++] = num;
    }
    void ShowAllData() {
        for (int i = 0; i < idx; i++)
            cout << arr[i] << ' ';
        cout << endl;
    }
    void SortData(const SortRule& functor) {
        for (int i = 0; i < (idx-1); i++)
        {
            for (int j = 0; j < (idx-1)-i; j++)
            {
                if (functor(arr[j], arr[j + 1])) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};
#pragma endregion


int main(void)
{
    /*First fsrc(111, 222);
    First fcpy;
    Second ssrc(333, 444);
    Second scpy;
    fcpy = fsrc;
    scpy = ssrc;
    fcpy.ShowData();
    scpy.ShowData();

    First fob1, fob2;
    Second sob1, sob2;
    fob1 = fob2 = fsrc;
    sob1 = sob2 = ssrc;

    fob1.ShowData();
    fob2.ShowData();
    sob1.ShowData();
    sob2.ShowData();*/

    /*Person man1("Lee dong woo", 29);
    Person man2("Yoon ji yul", 22);
    man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();*/

    /*Second1 ssrc(111, 222, 333, 444);
    Second1 scpy(0, 0, 0, 0);
    scpy = ssrc;
    scpy.ShowData();*/

    /*AAA obj1(12);
    cout << "****************" << endl;
    BBB obj2(obj1);
    cout << "****************" << endl;
    CCC obj3(obj1);*/

    /*BoundChectIntArray arr(5);
    for (int i = 0; i < 5; i++)
        arr[i] = (i + 1) * 11;
    for (int i = 0; i < 6; i++)
        cout << arr[i] << endl;*/

    /*BoundChectIntArray arr(5);
    for (int i = 0; i < 5; i++)
        arr[i] = (i + 1) * 11;
    ShowAllData(arr);*/

    /*BoundChectIntArray arr(3);
    arr[0] = new Point(3, 4);
    arr[1] = new Point(5, 6);
    arr[2] = new Point(7, 8);

    for (int i = 0; i < arr.GetArrLen(); i++)
        cout << *(arr[i]);

    delete arr[0];
    delete arr[1];
    delete arr[2];*/

    /*Point1* ptr = new Point1(3, 4);
    Point1* arr = new Point1[3];
    delete ptr;
    delete[]arr;*/

    /*Number num(20);
    num.ShowData();

    (*num) = 30;
    num->ShowData();
    (*num).ShowData();*/

    /*SmartPtr sptr1(new Pointer(1, 2));
    SmartPtr sptr2(new Pointer(2, 3));
    SmartPtr sptr3(new Pointer(4, 5));
    cout << *sptr1;
    cout << *sptr2;
    cout << *sptr3;

    sptr1->SetPos(10, 20);
    sptr2->SetPos(30, 40);
    sptr3->SetPos(50, 60);

    cout << *sptr1;
    cout << *sptr2;
    cout << *sptr3;*/

    DataStorage storage(5);
    storage.AddData(40);
    storage.AddData(30);
    storage.AddData(50);
    storage.AddData(20);
    storage.AddData(10);

    storage.SortData(AscendingSort());
    storage.ShowAllData();

    storage.SortData(DescendingSort());
    storage.ShowAllData();
    return 0;
}


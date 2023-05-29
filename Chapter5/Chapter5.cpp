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
    void ShowSimpleData(){
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


int main()
{
    // ClassInit
    /*SoSimple sim1(15, 30);
    cout << "생성 및 초기화 직전" << endl;
    SoSimple sim2 = sim1;
    cout << "생성 및 초기화 직후" << endl;
    sim2.ShowSimpleData();*/

    // ShallowCopyError
    Person man1("Lee dong woo", 29);
    Person man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}

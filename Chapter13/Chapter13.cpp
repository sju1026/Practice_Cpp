#include <iostream>
#include <cstring>
#include <cstdlib>
#include "PointTemplate.h"
#include "Point.h"
#pragma warning(disable:4996)
using namespace std;

#pragma region AddFunctionTemplate
template <typename T>
T Add(T num1, T num2) {
    cout << "T Add(T num1, T num2)" << endl;
    return num1 + num2;
}

int Add(int num1, int num2) {
    cout << "Add(int num1, int num2)" << endl;
    return num1 + num2;
}

double Add(double num1, double num2) {
    cout << "Add(double num1, double num2)" << endl;
    return num1 + num2;
}
#pragma endregion

#pragma region PrimitiveFunctionTemplate
template<class T1, class T2>
void ShowData(double num) {
    cout << (T1)num << ", " << (T2)num << endl;
}
#pragma endregion

#pragma region NeddSpecialFunctiontemplate
template <typename T1>
T1 Max(T1 a, T1 b) {
    return a > b ? a : b;
}

template <>
char* Max(char* a, char* b) {
    cout << "char* Max<char>(char* a, char* b)" << endl;
    return strlen(a) > strlen(b) ? a : b;
}
#pragma endregion

#pragma region PointClassTemplate
template <typename T>
class Point {
private:
    T xpos, ypos;
public:
    Point(T x = 0, T y = 0);
    void ShowPosition() const;
};

template <typename T>
Point<T> ::Point(T x, T y) : xpos(x), ypos(y) {}

template <typename T>
void Point<T>::ShowPosition() const {
    cout << '[' << xpos << ", " << ypos << ']' << endl;
}
#pragma endregion


int main(void)
{
    cout << Add(15, 20) << endl;
    cout << Add(2.9, 3.7) << endl;
    cout << Add<int>(3.2, 3.2) << endl;
    cout << Add<double>(3.14, 2.75) << endl;

    ShowData<char, int>(65);
    ShowData<char, int>(67);
    ShowData<char, double>(68.9);
    ShowData<short, double>(68.9);
    ShowData<short, double>(68.9);

    cout << Max(11, 15) << endl;
    cout << Max('T', 'Q') << endl;

    char str1[] = "Simple";
    char str2[] = "Best";
    cout << Max(str1, str2) << endl;

    Point<int> pos1(3, 4);
    pos1.ShowPosition();

    Point<double> pos2(2.4, 3.6);
    pos2.ShowPosition();

    Point<char> pos3('P', 'F');
    pos3.ShowPosition();


    return 0;
}

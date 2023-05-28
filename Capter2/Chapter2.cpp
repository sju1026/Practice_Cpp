#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;

#pragma region Bool
bool IsPositive(int num) {
    if (num <= 0)
        return false;
    else
        return true;
}
#pragma endregion

#pragma region Reference
void SwapByRef2(int &ref1, int &ref2) {
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

int& RefRetFuncOne(int& ref) {
    ref++;
    return ref;
}

int RefRetFuncTwo(int& ref) {
    ref++;
    return ref;
}
#pragma endregion

#pragma region New&Delete
char* MakeStrAdr(int len) {
    // char* str = (char*)malloc(sizeof(char) * len);
    char* str = new char[len];
    return str;
}

class Simple {
public:
    Simple() {
        cout << "I'm simple constructor!" << endl;
    }
};
#pragma endregion

#pragma region CtoC++

#pragma endregion

int main()
{
    /*int num = 10;
    int i = 0;

    cout << "true: " << true << endl;
    cout << "false: " << false << endl;

    while (true)
    {
        cout << i++ << ' ';
        if (i>num)
            break;
    }
    cout << endl;

    cout << "sizeof 1: " << sizeof(1) << endl;
    cout << "sizeof 0: " << sizeof(0) << endl;
    cout << "sizeof true: " << sizeof(true) << endl;
    cout << "sizeof false: " << sizeof(false) << endl;*/

    /*bool isPos;
    int num;
    cout << "Input number: ";
    cin >> num;

    isPos = IsPositive(num);
    if (isPos)
        cout << "Positive number" << endl;
    else
        cout << "Negative number" << endl;*/

    /*int arr[3] = { 1, 3, 5 };
    int& ref1 = arr[0];
    int& ref2 = arr[1];
    int& ref3 = arr[2];

    cout << ref1 << endl;
    cout << ref2 << endl;
    cout << ref3 << endl;*/

    /* int num = 12;
    int* ptr = &num;
    int** dptr = &ptr;

    int& ref = num;
    int* (&pref) = ptr;
    int** (&dpref) = dptr;

    cout << ref << endl;
    cout << *pref << endl;
    cout << **dptr << endl;*/

    /*int val1 = 10;
    int val2 = 20;

    SwapByRef2(val1, val2);
    cout << "val1: " << val1 << endl;
    cout << "val2: " << val2 << endl;*/

    /*int num1 = 1;
    //int& num2 = RefRetFuncOne(num1);
    int num2 = RefRetFuncOne(num1);

    //num1++;
    //num2++;
    //cout << "num1: " << num1 << endl;
    //cout << "num2: " << num2 << endl;

    num1 += 1;
    num2 += 100;
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;

    char* str = MakeStrAdr(20);
    strcpy(str, "I am so happy~");
    cout << str << endl;
    //free(str);
    delete[] str;

    cout << "case 1: ";
    Simple* sp1 = new Simple;

    cout << "case 2: ";
    Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1);

    cout << endl << "end of main" << endl;
    delete sp1;
    free(sp2);*/

    char str1[] = "Result";
    char str2[30];

    strcpy(str2, str1);
    printf("%s : %f \n", str1, sin(0.14));
    printf("%s : %f \n", str2, abs(-1.25));
    return 0;
}

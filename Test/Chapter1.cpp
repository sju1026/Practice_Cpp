// Test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
//using std::cin;
//using std::cout;
//using std::endl;
using namespace std;

#pragma region Standard IO
void Chapter1() {
    int num = 20;
    std::cout << "Hello World" << std::endl;
    std::cout << "Hello " << "World" << std::endl;
    std::cout << num << ' ' << "A";
    std::cout << ' ' << 3.14 << std::endl;

    int val1;
    std::cout << "첫 번째 숫자 입력: ";
    std::cin >> val1;

    int val2;
    std::cout << "두 번째 숫자 입력: ";
    std::cin >> val2;
    int result = val1 + val2;
    std::cout << "덧셈 결과" << result << std::endl;

    int val3, val4;
    int result1 = 0;
    std::cout << "두 개의 숫자 입력: ";
    std::cin >> val3 >> val4;

    if (val3 < val4)
    {
        for (int i = val3 + 1; i < val4; i++)
        {
            result1 += i;
        }
    }
    else
    {
        for (int i = val4 + 1; i < val3; i++)
        {
            result1 += i;
        }
    }

    std::cout << "두 수 사이의 정수 합: " << result1 << std::endl;

    char name[100];
    char lang[200];

    std::cout << "이름은 무엇입니까? ";
    std::cin >> name;

    std::cout << "좋아하는 프로그래밍 언어는 무엇인가요? ";
    std::cin >> lang;

    std::cout << "내 이름은 " << name << "입니다.\n";
    std::cout << "제일 좋아하는 언어는 " << lang << "입니다." << std::endl;
}
#pragma endregion

#pragma region Overloading
void MyFunc() {
    std::cout << "MyFunc(void) called" << std::endl;
}

void MyFunc(char c) {
    std::cout << "MyFunc(char c) called" << std::endl;
}

void MyFunc(int a, int b) {
    std::cout << "MyFunc(int a, int b) called" << std::endl;
}
#pragma endregion

#pragma region Default Value
int Adder(int num1 = 1, int num2 = 2) {
    return num1 + num2;
}

int BoxVoulum(int length, int width = 1, int height = 1);
#pragma endregion

#pragma region InlineFunc
inline int SQUARE(int x) {
    return x * x;
}
#pragma endregion

#pragma region NameSpace
//namespace BestComImp1 {
//    void SimpleFunc(void) {
//        std::cout << "BerstCom이 정의한 함수" << std::endl;
//    }
//}
//
//namespace ProgComImp1 {
//    void SimpleFunc(void) {
//        std::cout << "ProgCom이 정의한 함수" << std::endl;
//    }
//}

namespace BestComImp1 { void SimpleFunc(void); }

namespace BestComImp1 { void PrettyFunc(void); }

namespace ProgComImp1 { void SimpleFunc(void); }

namespace Hybrid {
    void HybFunc(void) {
        std::cout << "So simple function!" << std::endl;
        std::cout << "In namespace Hybrid!" << std::endl;
    }
}
#pragma endregion

int main()
{
    /*Chapter1();*/

    /*MyFunc();
    MyFunc('A');
    MyFunc(1, 2);
    return 0;*/

    /*std::cout << Adder() << std::endl;
    std::cout << Adder(5) << std::endl;
    std::cout << Adder(3,5) << std::endl;

    std::cout << "[3, 3, 3]: " << BoxVoulum(3,3,3) << std::endl;
    std::cout << "[5, 5, D]: " << BoxVoulum(5, 5) << std::endl;
    std::cout << "[7, D, D]: " << BoxVoulum(7) << std::endl;
    // std::cout << "[D, D, D]" << BoxVoulum() << std::endl;*/

    /*std::cout << SQUARE(5) << std::endl;
    std::cout << SQUARE(12) << std::endl;
    return 0;*/

    /*BestComImp1::SimpleFunc();
    using Hybrid::HybFunc;
    HybFunc();
    return 0;*/

    int num = 20;
    cout << "Hello World" << endl;
    cout << "Hello " << "World" << endl;
    cout << num << ' ' << 'A';
    cout << ' ' << 3.14 << endl;
    return 0;

}

int BoxVoulum(int length, int width, int height) {
    return length * width * height;
}

void BestComImp1::SimpleFunc(void) {
    std::cout << "BestCom이 정의한 함수" << std::endl;
    PrettyFunc();
    ProgComImp1::SimpleFunc();
}

void BestComImp1::PrettyFunc(void) {
    std::cout << "So Pretty!!" << std::endl;
}

void ProgComImp1::SimpleFunc(void) {
    std::cout << "ProgCom이 정의한 함수" << std::endl;
}

#pragma region Explanation
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
#pragma endregion


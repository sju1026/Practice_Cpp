#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#pragma region ConstObject
class SoSimple {
private:
    int num;
public:
    SoSimple(int n) :num(n) {}
    SoSimple& AddNum (int n) {
        num += n;
        return *this;
    }
    void ShowData() const {
        cout << "num: " << num << endl;
    }
};
#pragma endregion

#pragma region ConstOverloading
class SoSimple1 {
private:
    int num;
public:
    SoSimple1(int n) : num(n) {}
    SoSimple1& AddNum(int n) {
        num += n;
        return *this;
    }
    void Simple1Func() {
        cout << "Simple1Func: " << num << endl;
    }
    void Simple1Func() const {
        cout << "const SimpleFunc: " << num << endl;
    }
};

void YourFunc(const SoSimple1& obj) {
    obj.Simple1Func();
}
#pragma endregion

#pragma region MyFriendClass
class Girl;

class Boy {
private:
    int height;
    friend class Girl;
public:
    Boy(int len) : height(len) {}
    void ShowYourFriendInfo(Girl& frn);
};

class Girl {
private:
    char phNum[20];
public:
    Girl(const char* num) {
        strcpy(phNum, num);
    }
    void ShowYourFriendInfo(Boy& frn);
    friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl& frn) {
    cout << "Her phone number: " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy& frn) {
    cout << "His Height: " << frn.height << endl;
    }
#pragma endregion

#pragma region MyFriendFunction
class Point;

class PointOP {
private:
    int opcnt;
public:
    PointOP() : opcnt(0) {}
    Point PointAdd(const Point&, const Point&);
    Point PointSub(const Point&, const Point&);
    ~PointOP() {
        cout << "Operation times: " << opcnt << endl;
    }
};

class Point {
private:
    int x;
    int y;
public:
    Point(const int& xpos, const int& ypos) : x(xpos), y(ypos) {}
    friend Point PointOP::PointAdd(const Point&, const Point&);
    friend Point PointOP::PointSub(const Point&, const Point&);
    friend void ShowPointPos(const Point&);
};

Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2) {
    opcnt++;
    return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2) {
    opcnt++;
    return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}
#pragma endregion

#pragma region CComStatic
void Counter() {
    static int cnt;
    cnt++;
    cout << "Current cnt: " << cnt << endl;
}
#pragma endregion

#pragma region NeedGlobal
//int simObjCnt = 0;
//int cmxObjCnt = 0;

class SoSimple2 {
public: // private가 첫번째
    static int simObjCnt;
public:
    SoSimple2() {
        simObjCnt++;
        // cout << simObjCnt << "번째 SoSimple2 객체" << endl;
    }
};
int SoSimple2::simObjCnt = 0;

class SoComplex {
private:
    static int cmxObjCnt;
public:
    SoComplex() {
        cmxObjCnt++;
        cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
    }
    SoComplex(SoComplex& copy) {
        cmxObjCnt++;
        cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
    }
};
int SoComplex::cmxObjCnt = 0;
#pragma endregion

#pragma region ConstStaticMember
class CountryArea {
public:
    const static int RUSSIA = 1707540;
    const static int CANADA = 998467;
    const static int CHINA = 957290;
    const static int SOUTH_KOREA = 9922;
};

#pragma endregion

#pragma region Mutable
class SoSimple3 {
private:
    int num1;
    mutable int num2; // const 함수에 대해 예외를 둔다
public:
    SoSimple3(int n1, int n2) : num1(n1), num2(n2) {}
    void ShowSimpleData() const {
        cout << num1 << ", " << num2 << endl;
    }
    void CopyToNum2() const {
        num2 = num1;
    }
};
#pragma endregion


int main(void)
{
    // ConstObject
    /*const SoSimple obj(7);
    // obj.AddNum(20);
    obj.ShowData();*/

    // ConstOverloading
    /*SoSimple1 obj1(2);
    const SoSimple1 obj2(7);

    obj1.Simple1Func();
    obj2.Simple1Func();

    YourFunc(obj1);
    YourFunc(obj2);*/

    // MyFriendClass
    /*Boy boy(170);
    Girl girl("010-1234-5678");
    boy.ShowYourFriendInfo(girl);
    girl.ShowYourFriendInfo(boy);*/

    // MyFriendFunction
    /*Point pos1(1, 2);
    Point pos2(2, 4);
    PointOP op;

    ShowPointPos(op.PointAdd(pos1, pos2));
    ShowPointPos(op.PointSub(pos2, pos1));*/

    // CComStatic
    /*for (int i = 0; i< 10; i++)
    {
        Counter();
    }*/

    // NeedGlobal
    /*SoSimple2 sim1;
    SoSimple2 sim2;

    SoComplex com1;
    SoComplex com2 = com1;
    SoComplex();

    cout << SoSimple2::simObjCnt << "번째 SoSimple2 객체" << endl;
    SoSimple2 sim1;
    SoSimple2 sim2;

    cout << SoSimple2::simObjCnt << "번째 SoSimple2 객체" << endl;
    cout << sim1.simObjCnt << "번째 SoSimple2 객체" << endl;
    cout << sim2.simObjCnt << "번째 SoSimple2 객체" << endl;*/

    // ConstStaticMember
    /*cout << "러시아 면적: " << CountryArea::RUSSIA << " km/s" << endl;
    cout << "캐나다 면적: " << CountryArea::CANADA << " km/s" << endl;
    cout << "중국 면적: " << CountryArea::CHINA << " km/s" << endl;
    cout << "한국 면적: " << CountryArea::SOUTH_KOREA << " km/s" << endl;*/

    //Mutable
    SoSimple3 sm(1, 2);
    sm.ShowSimpleData();
    sm.CopyToNum2();
    sm.ShowSimpleData();
    return 0;
}

void ShowPointPos(const Point& pos) {
    cout << "x: " << pos.x << ", ";
    cout << "y: " << pos.y << endl;
}

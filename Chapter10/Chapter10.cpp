#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#pragma region FirstOperationOverloading
class Point {
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
    void ShowPosition() const {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point operator+(const Point& ref) {
        Point pos(xpos + ref.xpos, ypos + ref.ypos);
        return pos;
    }
}; 
#pragma endregion

#pragma region OverloadingOperation
class Point1 {
private:
    int xpos, ypos;
public:
    Point1(int x = 0, int y = 0) :xpos(x), ypos(y) {}
    void ShowPosition() const {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point1 operator+(const Point1& ref) {
        Point1 pos(xpos + ref.xpos, ypos + ref.ypos);
        return pos;
    }
};
#pragma endregion

#pragma region GFunctionOverloading
class Point2 {
private:
    int xpos, ypos;
public:
    Point2(int x = 0, int y = 0) :xpos(x), ypos(y) {}
    void ShowPosition() const {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    friend Point2 operator+(const Point2& pos1, const Point2& pos2);
};
Point2 operator+(const Point2& pos1, const Point2& pos2) {
    Point2 pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
    return pos;
}
#pragma endregion

#pragma region OneOpndOverloading
class Point3 {
private:
    int xpos, ypos;
public:
    Point3(int x = 0, int y = 0) :xpos(x), ypos(y) {}
    void ShowPosition() const {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point3& operator++() {
        xpos += 1;
        ypos += 1;
        return *this;
    }
    const Point3 operator++(int) {
        const Point3 retobj(xpos, ypos);
        xpos += 1;
        ypos += 1;
        return retobj;
    }
    friend Point3& operator--(Point3& ref);
    friend const Point3 operator--(Point3& ref, int);
};

Point3& operator--(Point3& ref) {
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

const Point3 operator--(Point3& ref, int) {
    const Point3 retobj(ref);
    ref.xpos -= 1;
    ref.ypos -= 1;
    return retobj;
}
#pragma endregion

#pragma region PointMultipleOperation
class Point4 {
private:
    int xpos, ypos;
public:
    Point4(int x = 0, int y = 0) :xpos(x), ypos(y) {}
    void ShowPosition() const {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point4 operator*(int times) {
        Point4 pos(xpos * times, ypos * times);
        return pos;
    }
    friend Point4 operator*(int times, Point4& ref);
};
Point4 operator*(int times, Point4& ref) {
    return ref * times;
}
#pragma endregion

#pragma region ConsoleOutput
namespace mystd {
    using namespace std;
    class ostream {
    public:
        ostream& operator<< (const char* str) {
            printf("%s", str);
            return *this;
        }
        ostream& operator<<(char* str) {
            printf("%c", str);
            return *this;
        }
        ostream& operator<<(int num) {
            printf("%d", num);
            return *this;
        }
        ostream& operator<<(double e) {
            printf("%g", e);
            return *this;
        }
        ostream& operator<<(ostream& (*fp)(ostream& ostm)) {
            return fp(*this);
        }
    };

    ostream& endl(ostream& ostm) {
        ostm << "\n";
        fflush(stdout);
        return ostm;
    }
    ostream cout;
}
#pragma endregion

#pragma region PointConsoleOutput
class Point5 {
private:
    int xpos, ypos;
public:
    Point5(int x = 0, int y = 0) :xpos(x), ypos(y) {}
    void ShowPosition() const {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    friend ostream& operator<<(ostream&, const Point5&);
};
ostream& operator<<(ostream& os, const Point5& pos) {
    os << '[' << pos.xpos << "," << pos.ypos << ']' << endl;
    return os;
}
#pragma endregion


int main(void)
{
    /*Point2 pos1(3, 4);
    Point2 pos2(10, 20);
    Point1 pos3 = pos1.operator+(pos2);
    Point2 pos3 = pos1 + pos2;
    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    Point3 pos(1, 2);
    ++pos;
    pos.ShowPosition();
    --pos;
    pos.ShowPosition();

    ++(++pos);
    pos.ShowPosition();
    --(--pos);
    pos.ShowPosition();*/

    /*Point3 pos(3, 5);
    Point3 cpy;
    cpy = pos--;
    cpy.ShowPosition();
    pos.ShowPosition();

    cpy = pos++;
    cpy.ShowPosition();
    pos.ShowPosition();*/

    /*Point4 pos(1, 2);
    Point4 cpy;
    
    cpy = pos * 3;
    cpy.ShowPosition();

    cpy = pos * 3 * 2;
    cpy.ShowPosition();*/

    /*Point4 pos(1, 2);
    Point4 cpy;
    cpy = 3 * pos;
    cpy.ShowPosition();

    cpy = 2 * pos * 3;
    cpy.ShowPosition();*/

    /*using mystd::cout;
    using mystd::endl;

    cout << "Simple String";
    cout << endl;
    cout << 3.14;
    cout << endl;
    cout << 123;
    endl(cout);
    cout << 3.14 << endl << 123 << endl;*/

    Point5 pos1(1, 3);
    cout << pos1;
    Point5 pos2(101, 303);
    cout << pos2;

    return 0;
}

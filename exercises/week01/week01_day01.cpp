// 第 1 周第 1 天：各类型的 sizeof 与取值范围
// 编译：g++ -std=c++17 -Wall week01_day01.cpp -o week01_day01.exe

#include <iostream>
#include <climits>
#include <cfloat>
using namespace std;

int main() {
    cout << "===== 整型 =====" << endl;

    // sizeof 返回字节数，1 字节 = 8 位
    cout << "char   : " << sizeof(char)
         << " 字节, 范围 " << CHAR_MIN << " ~ " << (int)CHAR_MAX << endl;

    cout << "short  : " << sizeof(short)
         << " 字节, 范围 " << SHRT_MIN << " ~ " << SHRT_MAX << endl;

    cout << "int    : " << sizeof(int)
         << " 字节, 范围 " << INT_MIN << " ~ " << INT_MAX << endl;

    cout << "long long : " << sizeof(long long)
         << " 字节, 范围 " << LLONG_MIN << " ~ " << LLONG_MAX << endl;

    cout << "\n===== 无符号整型 =====" << endl;
    // 无符号不能表示负数，最大值翻倍
    cout << "unsigned int 最大值: " << UINT_MAX << endl;

    cout << "\n===== 浮点型 =====" << endl;
    cout << "float       : " << sizeof(float)
         << " 字节, 精度约 " << FLT_DIG << " 位有效数字" << endl;
    cout << "double      : " << sizeof(double)
         << " 字节, 精度约 " << DBL_DIG << " 位有效数字" << endl;

    cout << "\n===== 字符型 =====" << endl;
    cout << "char        : " << sizeof(char) << " 字节" << endl;
    cout << "bool        : " << sizeof(bool) << " 字节" << endl;

    cout << "\n===== 动手改这里 =====" << endl;
    // 把下面的 2147483647 改成 2147483648 再运行，看看会发生什么
    int overflow_test = 2147483647;
    cout << "INT_MAX     = " << overflow_test << endl;

    return 0;
}

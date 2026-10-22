// 第 1 周第 7 天：猜数字（综合练习）
// 验收：随机数 1-100，提示大小，统计猜了几次
// 编译：g++ -std=c++17 -Wall week01_day07.cpp -o week01_day07.exe

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // 用当前时间做种子，否则每次运行都是同一串伪随机数
    srand((unsigned)time(0));
    int answer = rand() % 100 + 1;   // 1 ~ 100

    int guess = 0;
    int count = 0;

    cout << "我想了一个 1 到 100 之间的整数，你猜猜看。" << endl;

    while (true) {
        cout << "请输入你的猜测：";
        cin >> guess;
        count++;

        if (guess > answer) {
            cout << "大了" << endl;
        } else if (guess < answer) {
            cout << "小了" << endl;
        } else {
            cout << "对了！答案是 " << answer
                 << "，你猜了 " << count << " 次。" << endl;
            break;
        }
    }

    return 0;
}

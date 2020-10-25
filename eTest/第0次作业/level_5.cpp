//编写代码，在不使用第三个变量的情况下，交换两个变量的值
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << a << ' ' << b;

    return 0;
}
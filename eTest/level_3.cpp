//编写代码来将输入的任意一个小写字母变为大写字母
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char ch;
    cin >> ch;
    cout << (char)toupper(ch);

    return 0;
}
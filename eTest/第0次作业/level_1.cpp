//���Ե�����ĸ����ʽ��ӡ Hello world!
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "Hello World!";
    string::iterator si;
    for (si = str.begin(); si < str.end(); si++) {
        cout << *si << " ";
    }
    return 0;
}
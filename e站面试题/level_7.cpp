//编写代码来打印出如图 level_7_1 的九九乘法表
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d*%d=%02d\t", i, j, i * j);
		}
		cout << endl;
	}

	return 0;
}
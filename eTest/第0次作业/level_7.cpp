//��д��������ӡ����ͼ level_7_1 �ľžų˷���
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
//编写代码来实现冒泡排序
#include <iostream>
using namespace std;

void swaq(int& a, int& b);

int main()
{
	int a[] = { 9, 15, 22, 6, 8 };
	int size = sizeof(a) / sizeof(int);

	for (int i = 1; i < size; i++) {				
		bool exchange = false;
		for (int j = size - 1; j >= i; j--) {	
			if (a[j] < a[j-1]) {
				exchange = true;				
				swaq(a[j], a[j-1]);			
			}
		}
		if (exchange == false) {
			break;
		}
	}
	for (int i : a) {
		cout << i << endl;
	}

    return 0;
}

void swaq(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
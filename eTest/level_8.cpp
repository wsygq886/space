//编写代码来显示如图 level_8_1—4 的效果。
//从键盘输入层数，树有一系列逐渐增加的层。输入提示信息："请输入树的层数：" 输入格式要求："%d"
#include <iostream>
using namespace std;

void root(int level, char ch);

int main() {
	int level;
	cin >> level;
	for (int i = 2; i <= level + 1; i++) {			//按照大的层次树分为level层, 其中的层还可以继续分
		int blank = level;		//前导空格的数目, 从上到下递减
		for (int j = 1; j <= i; j++) {
			for (int k = 1; k <= blank; k++) {
				cout << ' ';
			}
			for (int l = 1; l <= 2 * j - 1; l++) {
				cout << '*';	//继续分之后就是j
			}
			cout << endl;
			blank--;
		}
	}
	root(level, ' ');
	cout << '|' << endl;
	root(level, '=');
	cout << 'v';
	root(level, '=');

	return 0;
}

void root(int level, char ch) {
	for (int i = 0; i < level; i++) {
		cout << ch;
	}
}
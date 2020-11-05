#include <iostream>
#include <stack>
#include <string>
using namespace std;

#define LEFT  true
#define RIGHT false

void ifm(bool tag, char ch, int index);
//打印错误信息并结束程序

int main() {
	string str;
	cin >> str;
	stack<char> sch;	//这是一个元素为char类型的栈
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' || str[i] == '[') {
			sch.push(str[i]);
			//读取到左括号入栈
		}
		else {
			//读取到右括号
			if (sch.empty()) {	//若栈为空返回true, 否则返回false
				ifm(LEFT, str[i], i);
				//若栈为空说明缺少左括号, 结束程序
				break;
			}
			switch (sch.top()) {
				//返回栈顶的左括号
			case '(':
				//栈顶为 ( 时
				if (str[i] != ')') {
					ifm(RIGHT, sch.top(), i);
					//若str[i]不为 ) , 说明此时缺少右括号和 ( 匹配, 结束程序
				}
				else {
					sch.pop();
					//右括号和栈顶的左括号匹配成功后, 栈顶的左括号弹出
				}
				break;
			case '[':
				//当栈顶为 [ 时
				if (str[i] != ']') {
					ifm(RIGHT, sch.top(), i);
					//若str[i]不为 ] , 说明此时的缺少右括号和 ] 匹配, 结束程序
				}
				else {
					sch.pop();
					//右括号和栈顶的左括号匹配成功后, 栈顶的左括号弹出
				}
				break;
			}
		}
	}
	while (sch.size() > 1) {
		//若栈内仍有括号, 为了输出第一个不配对的符号, 循环执行出栈直到栈内只有一个括号
		sch.pop();
	}
	if (!sch.empty()) {
		//遍历完表达式之后栈不为空, 说明有多余的左括号
		ifm(RIGHT, sch.top(), -1);
		//打印第一个不配对的符号, 下标显示0说明
	}
	else {
		cout << "匹配" << endl;
	}

	return 0;
}

void ifm(bool tag, char ch, int index) {
	cout << "此串括号匹配不合法" << endl;
	cout << index + 1 << ": ";
	if (tag) {
		cout << "?-" << ch << endl;
	}
	else {
		cout << ch << "-?" << endl;
	}
	exit(0);
}
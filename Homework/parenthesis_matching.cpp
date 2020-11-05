#include <iostream>
#include <stack>
#include <string>
using namespace std;

void ifm(void);
//打印错误信息并结束程序

int main() {
	string str;
	cin >> str;
	stack<char> sch;	//这是一个元素为char类型的栈
	for (string::iterator it = str.begin(); it < str.end(); it++) {
		//it是str的迭代器, *it就是一个char, 相当于str[0,1,...]
		if (*it == '(' || *it == '[') {
			sch.push(*it);
			//读取到左括号入栈
		}
		else {
			//读取到右括号
			if (sch.empty()) {	//若栈为空返回true, 否则返回false
				ifm();
				//若栈为空说明有多余的右括号, 结束程序
				break;
			}
			switch (sch.top()) {
				//返回栈顶的左括号
			case '(':
				//栈顶为 ( 时
				if (*it != ')') {
					ifm();
					//若*it不为 ) , 说明此时的右括号没有左括号和他匹配, 结束程序
				}
				else {
					sch.pop();
					//右括号和栈顶的左括号匹配成功后, 栈顶的左括号弹出
				}
				break;
			case '[':
				//当栈顶为 [ 时
				if (*it != ']') {
					ifm();
					//若*it不为 ] , 说明此时的右括号没有左括号和他匹配, 结束程序
				}
				else {
					sch.pop();
					//右括号和栈顶的左括号匹配成功后, 栈顶的左括号弹出
				}
				break;
			}
		}
	}
	if (!sch.empty()) {
		//遍历完表达式之后栈不为空, 说明有多余的左括号
		ifm();
	}
	else {
		cout << "匹配" << endl;
	}

	return 0;
}


void ifm(void) {
	cout << "此串括号匹配不合法" << endl;
	exit(0);
}
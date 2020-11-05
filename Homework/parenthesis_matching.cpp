#include <iostream>
#include <stack>
#include <string>
using namespace std;

void ifm(void);
//��ӡ������Ϣ����������

int main() {
	string str;
	cin >> str;
	stack<char> sch;	//����һ��Ԫ��Ϊchar���͵�ջ
	for (string::iterator it = str.begin(); it < str.end(); it++) {
		//it��str�ĵ�����, *it����һ��char, �൱��str[0,1,...]
		if (*it == '(' || *it == '[') {
			sch.push(*it);
			//��ȡ����������ջ
		}
		else {
			//��ȡ��������
			if (sch.empty()) {	//��ջΪ�շ���true, ���򷵻�false
				ifm();
				//��ջΪ��˵���ж����������, ��������
				break;
			}
			switch (sch.top()) {
				//����ջ����������
			case '(':
				//ջ��Ϊ ( ʱ
				if (*it != ')') {
					ifm();
					//��*it��Ϊ ) , ˵����ʱ��������û�������ź���ƥ��, ��������
				}
				else {
					sch.pop();
					//�����ź�ջ����������ƥ��ɹ���, ջ���������ŵ���
				}
				break;
			case '[':
				//��ջ��Ϊ [ ʱ
				if (*it != ']') {
					ifm();
					//��*it��Ϊ ] , ˵����ʱ��������û�������ź���ƥ��, ��������
				}
				else {
					sch.pop();
					//�����ź�ջ����������ƥ��ɹ���, ջ���������ŵ���
				}
				break;
			}
		}
	}
	if (!sch.empty()) {
		//��������ʽ֮��ջ��Ϊ��, ˵���ж����������
		ifm();
	}
	else {
		cout << "ƥ��" << endl;
	}

	return 0;
}


void ifm(void) {
	cout << "�˴�����ƥ�䲻�Ϸ�" << endl;
	exit(0);
}
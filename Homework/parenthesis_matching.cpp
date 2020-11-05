#include <iostream>
#include <stack>
#include <string>
using namespace std;

#define LEFT  true
#define RIGHT false

void ifm(bool tag, char ch, int index);
//��ӡ������Ϣ����������

int main() {
	string str;
	cin >> str;
	stack<char> sch;	//����һ��Ԫ��Ϊchar���͵�ջ
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' || str[i] == '[') {
			sch.push(str[i]);
			//��ȡ����������ջ
		}
		else {
			//��ȡ��������
			if (sch.empty()) {	//��ջΪ�շ���true, ���򷵻�false
				ifm(LEFT, str[i], i);
				//��ջΪ��˵��ȱ��������, ��������
				break;
			}
			switch (sch.top()) {
				//����ջ����������
			case '(':
				//ջ��Ϊ ( ʱ
				if (str[i] != ')') {
					ifm(RIGHT, sch.top(), i);
					//��str[i]��Ϊ ) , ˵����ʱȱ�������ź� ( ƥ��, ��������
				}
				else {
					sch.pop();
					//�����ź�ջ����������ƥ��ɹ���, ջ���������ŵ���
				}
				break;
			case '[':
				//��ջ��Ϊ [ ʱ
				if (str[i] != ']') {
					ifm(RIGHT, sch.top(), i);
					//��str[i]��Ϊ ] , ˵����ʱ��ȱ�������ź� ] ƥ��, ��������
				}
				else {
					sch.pop();
					//�����ź�ջ����������ƥ��ɹ���, ջ���������ŵ���
				}
				break;
			}
		}
	}
	while (sch.size() > 1) {
		//��ջ����������, Ϊ�������һ������Եķ���, ѭ��ִ�г�ջֱ��ջ��ֻ��һ������
		sch.pop();
	}
	if (!sch.empty()) {
		//��������ʽ֮��ջ��Ϊ��, ˵���ж����������
		ifm(RIGHT, sch.top(), -1);
		//��ӡ��һ������Եķ���, �±���ʾ0˵��
	}
	else {
		cout << "ƥ��" << endl;
	}

	return 0;
}

void ifm(bool tag, char ch, int index) {
	cout << "�˴�����ƥ�䲻�Ϸ�" << endl;
	cout << index + 1 << ": ";
	if (tag) {
		cout << "?-" << ch << endl;
	}
	else {
		cout << ch << "-?" << endl;
	}
	exit(0);
}
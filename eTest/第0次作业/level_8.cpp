//��д��������ʾ��ͼ level_8_1��4 ��Ч����
//�Ӽ����������������һϵ�������ӵĲ㡣������ʾ��Ϣ��"���������Ĳ�����" �����ʽҪ��"%d"
#include <iostream>
using namespace std;

void root(int level, char ch);

int main() {
	int level;
	cin >> level;
	for (int i = 2; i <= level + 1; i++) {			//���մ�Ĳ������Ϊlevel��, ���еĲ㻹���Լ�����
		int blank = level;		//ǰ���ո����Ŀ, ���ϵ��µݼ�
		for (int j = 1; j <= i; j++) {
			for (int k = 1; k <= blank; k++) {
				cout << ' ';
			}
			for (int l = 1; l <= 2 * j - 1; l++) {
				cout << '*';	//������֮�����j
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
#include <iostream>
#include <string>
using namespace std;

struct Stu {
    string name;
    int ID;
    Stu();          //Stu�Ĺ��캯��, �����Զ���ʼ��
    void input();   //���ڼ�������������ѧ�ŵķ���
    void show();    //�����ڿ���̨���������ѧ�ŵķ���
};

const int SIZE = 10;    //����Ĵ�С

struct Stu_list {
    Stu data[SIZE];
    int length;                         //���浱ǰ����
    Stu_list();                         //Stu_list�Ĺ��캯��
    bool nameSearch(const string& name);//���ո�����name���Ҷ�Ӧ��Ա
    bool insert();                      //��ָ��λ�ò���һ����Ա���ɹ������棬���򷵻ؼ�
    bool push_back(const Stu& e);       //�ڱ�β����һ���³�Ա
    bool erase();                       //��ָ��λ��ɾ��һ����Ա���ɹ������棬���򷵻ؼ�
    void Sort();                        //���ո�����ID���ֲ��Ҷ�Ӧ��Ա
    int BinarySearch(const int ID);     //��������
    void dispList();                    //��ӡ����˳���
    void storage();                     //��ʾ��ǰ�����ʹ洢״��
    void clear();                       //��length���㣬���˳���
};

string info[7] = {
    "1)¼���µ�ѧ���ź�",
    "2)ɾ����ǰѧ����Ϣ",
    "3)��ָ��λ��֮�����ѧ����Ϣ",
    "4)ɾ��ָ��λ�õ�ѧ����Ϣ",
    "5)����������˳�����",
    "6)��ѧ�Ž��ж��ֲ���",
    "7)����Ļ���������ѧ��������",
};

int main() {
    Stu_list sl;
    int option;
    int pos;
    Stu s;
    while (true) {
        sl.storage();
        for (int i = 0; i < 7; i++)
            cout << info[i] << endl;
        cin >> option;
        switch (option) {
        case 1:
            int total;
            cout << "����������:";
            cin >> total;
            for (int i = 0; i < total; i++) {
                s.input();
                sl.push_back(s);
            }
            break;
        case 2:
            sl.clear();
            break;
        case 3:
            if (!sl.insert())
                cout << "λ�ô���";
            break;
        case 4:
            if (!sl.erase())
                cout << "λ�ô���";
            break;
        case 5:
            cout << "����������";
            cin >> s.name;
            if (!sl.nameSearch(s.name))
                cout << "������";
            break;
        case 6:
            cout << "������ѧ��";
            cin >> s.ID;
            sl.Sort();
            int rec;
            rec = sl.BinarySearch(s.ID);
            if (rec == -1)
                cout << "������";
            else
                sl.data[rec].show();
            break;
        case 7:
            sl.dispList();
            break;
        default:
            exit(0);
        }
        system("pause");
        system("cls");
    }
    return 0;
}

Stu::Stu() : name("undefine"), ID(-1) {}

void Stu::input() {
    cout << "������������ѧ��:";
    cin >> name >> ID;
}

void Stu::show() {
    cout << name << '\t' << ID << endl;
}

Stu_list::Stu_list() : length(0) {}

bool Stu_list::push_back(const Stu& e) {
    if (length == SIZE)
        return false;
    data[length] = e;
    length++;
    return true;
}

void Stu_list::storage() {
    cout << "�洢״��\n";
    if (length == 0) {
        cout << "δ¼������";
    }
    else if (length == SIZE) {
        cout << "����";
    }
    else {
        printf("��¼��%d,���ܼ���¼��%d��", length, SIZE - length);
    }
    cout << endl << endl;
}

void Stu_list::clear() {
    length = 0;
}

bool Stu_list::insert() {
    int i;
    cout << "������λ��";
    cin >> i;
    if (i-- < 1 || i > length + 1)
        return false;
    for (int j = length; j > i; j--)
        data[j] = data[j - 1];
    data[i].input();
    length++;
    return true;
}

bool Stu_list::erase() {
    int i;
    cout << "������λ��";
    cin >> i;
    if (i-- < 1 || i > length)
        return false;
    for (int j = i; j < length - 1; j++)
        data[j] = data[j + 1];
    length--;
    return true;
}
bool Stu_list::nameSearch(const string& name) {
    int i = 0;
    while (i < length && data[i].name != name)
        i++;
    if (i >= length)
        return false;
    data[i].show();
    return true;
}
void Stu_list::Sort() {
    for (int i = 1; i < length; i++) {
        Stu tmp;
        if (data[i].ID < data[i - 1].ID) { //ֻ�е������ʱ��Ž�����������
            tmp = data[i];
            int j = i - 1;
            do {					//��a[i]�Ĳ���λ��
                data[j + 1] = data[j];	//���ؼ��ִ���a[i]�ļ�¼�����
                j--;
            } while ((j >= 0) && (data[j].ID > tmp.ID));
            data[j + 1] = tmp;		//��j+1������
        }
    }
}

int Stu_list::BinarySearch(const int ID) {
    int start = 0, end = length;
    int mid;
    while (start < end) {
        mid = (start + end) / 2;
        if (data[mid].ID == ID)
            return mid;
        else if (data[mid].ID < ID)
            start = mid + 1;
        else
            end = mid;
    }
    return -1;
}

void Stu_list::dispList() {
    if (length == 0)
        return;
    for (int i = 0; i < length; i++)
        data[i].show();
}
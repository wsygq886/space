#include <iostream>
#include <string>
using namespace std;

struct Stu {
    string name;
    int ID;
    Stu();          //Stu的构造函数, 用于自动初始化
    void input();   //用于键盘输入姓名和学号的方法
    void show();    //用于在控制台输出姓名和学号的方法
};

const int SIZE = 10;    //数组的大小

struct Stu_list {
    Stu data[SIZE];
    int length;                         //保存当前人数
    Stu_list();                         //Stu_list的构造函数
    bool nameSearch(const string& name);//按照给定的name查找对应成员
    bool insert();                      //在指定位置插入一名成员，成功返回真，否则返回假
    bool push_back(const Stu& e);       //在表尾加入一名新成员
    bool erase();                       //在指定位置删除一名成员，成功返回真，否则返回假
    void Sort();                        //按照给定的ID二分查找对应成员
    int BinarySearch(const int ID);     //二分搜索
    void dispList();                    //打印整个顺序表
    void storage();                     //显示当前人数和存储状况
    void clear();                       //将length置零，清空顺序表
};

string info[7] = {
    "1)录入新的学生信号",
    "2)删除当前学生信息",
    "3)在指定位置之后插入学生信息",
    "4)删除指定位置的学生信息",
    "5)按姓名进行顺序查找",
    "6)按学号进行二分查找",
    "7)在屏幕上输出所有学生的数据",
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
            cout << "请输入人数:";
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
                cout << "位置错误";
            break;
        case 4:
            if (!sl.erase())
                cout << "位置错误";
            break;
        case 5:
            cout << "请输入姓名";
            cin >> s.name;
            if (!sl.nameSearch(s.name))
                cout << "不存在";
            break;
        case 6:
            cout << "请输入学号";
            cin >> s.ID;
            sl.Sort();
            int rec;
            rec = sl.BinarySearch(s.ID);
            if (rec == -1)
                cout << "不存在";
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
    cout << "请输入姓名和学号:";
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
    cout << "存储状况\n";
    if (length == 0) {
        cout << "未录入数据";
    }
    else if (length == SIZE) {
        cout << "已满";
    }
    else {
        printf("已录入%d,还能继续录入%d人", length, SIZE - length);
    }
    cout << endl << endl;
}

void Stu_list::clear() {
    length = 0;
}

bool Stu_list::insert() {
    int i;
    cout << "请输入位置";
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
    cout << "请输入位置";
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
        if (data[i].ID < data[i - 1].ID) { //只有当反序的时候才进入排序流程
            tmp = data[i];
            int j = i - 1;
            do {					//找a[i]的插入位置
                data[j + 1] = data[j];	//将关键字大于a[i]的记录向后移
                j--;
            } while ((j >= 0) && (data[j].ID > tmp.ID));
            data[j + 1] = tmp;		//在j+1出插入
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
#include <iostream>
#include <queue>
using namespace std;

typedef int  VertexType;//顶点类型 假定为int
typedef char ArcType;   //边的类型 假定为char

typedef struct _arcnode {
    int adjvex;         //邻接点下标
    struct _arcnode* next;
}arcnode;

typedef struct _vertexnode {
    VertexType data;    //存储顶点信息
    arcnode* head;      //指向邻接表表头的指针
}vertexnode;

typedef struct _Lgraph {
    vertexnode* arr;    //顶点数组
    int num_vexs;       //顶点个数
}lgraph;


void initGraph(lgraph*& g);

void createGraph(lgraph* g);

void DFS(lgraph* g, int i);

void DFS_Traverse(lgraph* g);

void BFS_Traverse(lgraph* g);

int main()
{
    lgraph* g;
    initGraph(g);
    createGraph(g);
    DFS_Traverse(g);
    cout << endl;
    BFS_Traverse(g);

    return 0;
}

void initGraph(lgraph*& g)
{
    g = new lgraph;
    int n;
    cin >> n;
    g->num_vexs = n;
    g->arr = new vertexnode[n];
}

void createGraph(lgraph* g)
{
    for (int i = 0; i < g->num_vexs; i++) {
        cin >> g->arr[i].data;
    }
    cin.get();
    arcnode* p, * tail;

    for (int i = 0; i < g->num_vexs; i++) {
        char adj;
        bool first = true;
        while ((adj = cin.get()) != '#') {
            p = new arcnode;
            p->adjvex = adj - '0';
            if (first == true) {
                g->arr[i].head = tail = p;
                first = false;
            }
            else {
                tail->next = p;
                tail = p;
            }
        }
        if (first == false) {
            tail->next = NULL;
        }
        else {
            g->arr[i].head = NULL;
        }
        cin.get();
    }
}

bool* visited;

void DFS(lgraph* g, int i)
{
    visited[i] = true;
    cout << g->arr[i].data << ' ';
    arcnode* p;
    p = g->arr[i].head;
    while (p != NULL) {
        if (!visited[p->adjvex]) {
            DFS(g, p->adjvex);
        }
        p = p->next;
    }
}

void DFS_Traverse(lgraph* g)
{
    visited = new bool[g->num_vexs];
    for (int i = 0; i < g->num_vexs; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < g->num_vexs; i++) {
        if (!visited[i]) {
            DFS(g, i);
        }
    }
}

void BFS_Traverse(lgraph* g)
{
    visited = new bool[g->num_vexs];
    for (int i = 0; i < g->num_vexs; i++) {
        visited[i] = false;
    }
    queue<int> q;
    for (int i = 0; i < g->num_vexs; i++) {
        if (!visited[i]) {
            visited[i] = true;
            cout << g->arr[i].data;
            q.push(i);
            arcnode* p;
            while (!q.empty()) {
                i = q.front();
                q.pop();
                p = g->arr[i].head;
                while (p) {
                    if (!visited[p->adjvex]) {
                        visited[p->adjvex] = true;
                        cout << g->arr[p->adjvex].data;
                        q.push(p->adjvex);
                    }
                    p = p->next;
                }
            }
        }
    }
}

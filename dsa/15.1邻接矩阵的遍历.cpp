#include <iostream>
#include <queue>
using namespace std;

typedef int  VertexType;	//��������, �ٶ�Ϊint
typedef char ArcType;		//�ߵ�����, �ٶ�Ϊchar

typedef struct _mgraph {
	VertexType* vexs;   //������һά��
	ArcType** arc;      //�ڽӾ���
	int num_vexs;       //������Ŀ
}mgraph;

void initGraph(mgraph*& g);

void createGraph(mgraph* g);

void DFS(mgraph* g, int i);

void DFS_Traverse(mgraph* g);

void BFS_Traverse(mgraph* g);

void destroyGraph(mgraph* g);

int main()
{
	mgraph* g;
	initGraph(g);
	createGraph(g);
	DFS_Traverse(g);
	cout << endl;
	BFS_Traverse(g);
	destroyGraph(g);
	return 0;
}

bool* visited;

void initGraph(mgraph*& g)
{
	g = new mgraph;
	int n;
	cin >> n;
	g->num_vexs = n;
	g->vexs = new VertexType[n];
	g->arc = new ArcType * [n];
	for (int i = 0; i < n; i++) {
		g->arc[i] = new ArcType[n];
	}
}

void createGraph(mgraph* g)
{
	for (int i = 0; i < g->num_vexs; i++) {
		cin >> g->vexs[i];
	}
	cin.get();
	for (int i = 0; i < g->num_vexs; i++) {
		for (int j = 0; j < g->num_vexs; j++) {
			cin >> g->arc[i][j];
		}
		cin.get();
	}
}

void DFS(mgraph* g, int i)
{
	visited[i] = true;
	cout << g->vexs[i] << ' ';
	for (int j = 0; j < g->num_vexs; j++) {
		if (g->arc[i][j] == 1 && !visited[j]) {
			DFS(g, j);
		}
	}
}

void DFS_Traverse(mgraph* g)
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
	delete[] visited;
}

void BFS_Traverse(mgraph* g)
{
	visited = new bool[g->num_vexs];
	for (int i = 0; i < g->num_vexs; i++) {
		visited[i] = false;
	}
	queue<int> q;
	for (int i = 0; i < g->num_vexs; i++) {
		if (!visited[i]) {
			visited[i] = true;
			cout << g->vexs[i] << ' ';
			q.push(i);
			while (!q.empty()) {
				i = q.front();
				q.pop();
				for (int j = 0; j < g->num_vexs; j++) {
					if (g->arc[i][j] == '1' && !visited[j]) {
						visited[j] = true;
						cout << g->vexs[j] << ' ';
						q.push(j);
					}
				}
			}
		}
	}
	delete[] visited;
}

void destroyGraph(mgraph* g)
{
	delete[] g->vexs;
	for (int i = 0; i < g->num_vexs; i++) {
		delete[] g->arc[i];
	}
}
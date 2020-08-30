#include <iostream>
using namespace std;

typedef int  VertexType;	//��������, �ٶ�Ϊint
typedef short ArcType;		//�ߵ�����, �ٶ�Ϊshort

typedef struct _mgraph {
	VertexType* vexs;   //������һά��
	ArcType** arc;      //�ڽӾ���
	int num_vexs;       //������Ŀ
}mgraph;

void initGraph(mgraph*& g);

void createGraph(mgraph* g);

void MST_Prim(mgraph* g);

int main()
{
	mgraph* g;
	initGraph(g);
	createGraph(g);

	MST_Prim(g);



	return 0;
}

void initGraph(mgraph*& g)
{
	int n;
	cin >> n;
	if (n == 0) {
		exit(0);
	}
	g = new mgraph;
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
	for (int i = 0; i < g->num_vexs; i++) {
		for (int j = 0; j < g->num_vexs; j++) {
			cin >> g->arc[i][j];
		}
	}
}

void MST_Prim(mgraph* g)
{
	ArcType* lowcost;   //�洢Ȩֵ������
	lowcost = new ArcType[g->num_vexs];
	lowcost[0] = 0;     //��v0��ΪС���ĸ��ڵ�

	int* adjvex;
	adjvex = new int[g->num_vexs];
	adjvex[0] = 0;

	for (int i = 1; i < g->num_vexs; i++) {
		lowcost[i] = g->arc[0][i];  //����Щ��v0�ڽӵıߵ�Ȩֵ�Ž������� (���ڽӿ����ڽӵ����������)
		adjvex[i] = 0;              //��ʼ�������ֻ��v0һ���ڵ�
	}

	int min;    //һ����Χ�ڵ���СȨֵ
	int min_k;  //�洢��СȨֵ�Ķ����±�
	const ArcType Inf = 32767;  //Ȩֵ�������

	for (int i = 1; i < g->num_vexs; i++) {
		min = Inf;
		min_k = 0;
		for (int j = 1; j < g->num_vexs; j++) {
			//��lowcost�����ҵ�Ȩ����С�ı�
			if (lowcost[j] != 0 && lowcost[j] < min) {  //lowcost��Ԫ��Ϊ0���ʾ�ö���������MST��
				min = lowcost[j];
				min_k = j;
			}
		}
		cout << adjvex[min_k] << ' ' << min_k << endl;
		lowcost[min_k] = 0; //���ö�������MST��

		for (int j = 1; j < g->num_vexs; j++) {
			if (lowcost[j] != 0 && g->arc[min_k][j] < lowcost[j]) {
				lowcost[j] = g->arc[min_k][j];  //��С��Ȩֵ����lowcost��Ӧλ��
				adjvex[j] = min_k;  //������СȨֵ�ıߵ�����һ������, ��MST�����еĶ���, ����adjvex
			}
		}
		//��lowcost��adjvex׼���ú�, ������һ��ѭ�������lowcost��������
	}
	delete[] adjvex;
	delete[] lowcost;
}

/*
9
0       1       2       3       4       5       6       7       8
0	    10	    32767	32767	32767	11	    32767	32767	32767
10      0	    18  	32767	32767	32767	16	    32767	12
32767	18  	0	    22  	32767	32767	32767	32767	8
32767	32767	22	    0	    22	    32767	24	    16	    21
32767	32767	32767	22	    0	    26	    32767	7	    32767
11	    32767	32767	32767	26  	0   	17	    32767	32767
32767	16	    32767	24    	32767	17	    0	    19  	32767
32767	32767	32767	16	    7	    32767	19  	0	    32767
32767	12	    8	    21	    32767	32767	32767	32767	0
*/
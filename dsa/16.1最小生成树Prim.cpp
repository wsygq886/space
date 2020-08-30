#include <iostream>
using namespace std;

typedef int  VertexType;	//顶点类型, 假定为int
typedef short ArcType;		//边的类型, 假定为short

typedef struct _mgraph {
	VertexType* vexs;   //顶点数一维组
	ArcType** arc;      //邻接矩阵
	int num_vexs;       //顶点数目
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
	ArcType* lowcost;   //存储权值的数组
	lowcost = new ArcType[g->num_vexs];
	lowcost[0] = 0;     //以v0作为小树的根节点

	int* adjvex;
	adjvex = new int[g->num_vexs];
	adjvex[0] = 0;

	for (int i = 1; i < g->num_vexs; i++) {
		lowcost[i] = g->arc[0][i];  //将那些和v0邻接的边的权值放进数组里 (不邻接看成邻接但距离无穷大)
		adjvex[i] = 0;              //初始化这棵树只有v0一个节点
	}

	int min;    //一定范围内的最小权值
	int min_k;  //存储最小权值的顶点下标
	const ArcType Inf = 32767;  //权值的无穷大

	for (int i = 1; i < g->num_vexs; i++) {
		min = Inf;
		min_k = 0;
		for (int j = 1; j < g->num_vexs; j++) {
			//在lowcost里面找到权重最小的边
			if (lowcost[j] != 0 && lowcost[j] < min) {  //lowcost的元素为0则表示该顶点已纳入MST中
				min = lowcost[j];
				min_k = j;
			}
		}
		cout << adjvex[min_k] << ' ' << min_k << endl;
		lowcost[min_k] = 0; //将该顶点纳入MST中

		for (int j = 1; j < g->num_vexs; j++) {
			if (lowcost[j] != 0 && g->arc[min_k][j] < lowcost[j]) {
				lowcost[j] = g->arc[min_k][j];  //较小的权值存入lowcost相应位置
				adjvex[j] = min_k;  //这条较小权值的边的其中一个顶点, 在MST中已有的顶点, 存入adjvex
			}
		}
		//把lowcost和adjvex准备好后, 进入下一轮循环后遍历lowcost输出顶点对
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
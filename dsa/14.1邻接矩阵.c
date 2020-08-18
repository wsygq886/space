#include <stdio.h>
#include <stdlib.h>

#define OK		0
#define ERROR	1

typedef int  VertexType;
typedef char ArcType;

typedef struct _arcnode {
	int adjvex;	//邻接点下标
	int weight;	//权重
	struct _arcnode* next;
}arcnode;

typedef struct _vertexnode {
	VertexType data;
	arcnode* head;
}vertexnode;

typedef struct _Lgraph {
	vertexnode* arr;
	int num_vexs;
}lgraph;



void
initGraph(lgraph** g);

void
createGraph(lgraph* g);

int main()
{
	lgraph* g;
	initGraph(&g);
	createGraph(g);

	return 0;
}

void initGraph(lgraph** g)
{
	int n;
	*g = (lgraph*)malloc(sizeof(lgraph));
	printf("输入顶点数\n");
	scanf("%d", &n);
	(*g)->num_vexs = n;
	(*g)->arr = (VertexType*)malloc(sizeof(VertexType) * n);
}

void createGraph(lgraph* g)
{
	int i;
	arcnode* p;
	printf("从0开始按照编号顺序输入顶点值\n");
	for (i = 0; i < g->num_vexs; i++) {
		scanf("%d", &g->arr[i].data);
	}
	printf("从0开始按照编号顺序输入邻接表, 所以输入数据都不要用空格分开, 输入两个#表示结束\n");
	for (i = 0; i < g->num_vexs; i++) {
		char adj, weight;
		arcnode* tail;
		p = (arcnode*)malloc(sizeof(arcnode));
		g->arr[i].head = tail = p;
		while (adj = getchar() != '#' && weight = getchar() != '#') {
			p = (arcnode*)malloc(sizeof(arcnode));
			p->adjvex = adj;
			p->weight = weight;
			tail->next = p;
			tail = p;
		}
		tail->next = NULL;
	}
}


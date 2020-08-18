#include <stdio.h>
#include <stdlib.h>

typedef int  VertexType;
typedef char ArcType;

typedef struct _arcnode {
	int adjvex;	//�ڽӵ��±�
	int weight;	//Ȩ��
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

void
printGraph(lgraph* g);

int main()
{
	lgraph* g;
	initGraph(&g);
	createGraph(g);
	printGraph(g);

	return 0;
}

void initGraph(lgraph** g)
{
	int n;
	*g = (lgraph*)malloc(sizeof(lgraph));
	printf("���붥����\n");
	scanf("%d", &n);
	(*g)->num_vexs = n;
	(*g)->arr = (vertexnode*)malloc(sizeof(vertexnode) * n);
}

void createGraph(lgraph* g)
{
	int i;
	arcnode* p, * tail;
	printf("��0��ʼ���ձ��˳�����붥��ֵ\n");
	for (i = 0; i < g->num_vexs; i++) {
		scanf("%d", &g->arr[i].data);
	}
	getchar();
	printf("��0��ʼ���ձ��˳�������ڽӱ�, �����������ݶ���Ҫ�ÿո�ֿ�, ����#��ʾ����\n");
	for (i = 0; i < g->num_vexs; i++) {
		char adj, weight;
		p = (arcnode*)malloc(sizeof(arcnode));
		g->arr[i].head = tail = p;
		while ((adj = getchar()) != '#' && (weight = getchar()) != '#') {
			p = (arcnode*)malloc(sizeof(arcnode));
			p->adjvex = adj - '0';
			p->weight = weight - '0';
			tail->next = p;
			tail = p;
		}
		tail->next = NULL;
		getchar();
	}
}

void
printGraph(lgraph* g)
{
	int i;
	arcnode* p;

	for (i = 0; i < g->num_vexs; i++) {
		for (p = g->arr[i].head->next; p != NULL; p = p->next) {
			printf("%d %d ", p->adjvex, p->weight);
		}
		printf("\n");
	}
}


#include <stdio.h>
#include <stdlib.h>

#define OK		0
#define ERROR	1

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
	printf("���붥����\n");
	scanf("%d", &n);
	(*g)->num_vexs = n;
	(*g)->arr = (VertexType*)malloc(sizeof(VertexType) * n);
}

void createGraph(lgraph* g)
{
	int i;
	arcnode* p;
	printf("��0��ʼ���ձ��˳�����붥��ֵ\n");
	for (i = 0; i < g->num_vexs; i++) {
		scanf("%d", &g->arr[i].data);
	}
	printf("��0��ʼ���ձ��˳�������ڽӱ�, �����������ݶ���Ҫ�ÿո�ֿ�, ��������#��ʾ����\n");
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


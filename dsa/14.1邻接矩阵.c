#include <stdio.h>
#include <stdlib.h>

typedef int  VertexType;
typedef char ArcType;

typedef struct _mgraph {
	VertexType* vexs;
	ArcType** arc;
	int num_vexs;
}mgraph;

void
initGraph(mgraph** g);

void
createGraph(mgraph* g);

int main()
{
	mgraph* g;
	initGraph(&g);
	createGraph(g);

	return 0;
}

void
initGraph(mgraph** g)
{
	int i;
	*g = (mgraph*)malloc(sizeof(mgraph));
	printf("���붥����\n");
	scanf("%d", &(*g)->num_vexs);

	(*g)->vexs = (VertexType*)malloc(sizeof(VertexType) * (*g)->num_vexs);
	(*g)->arc = (ArcType**)malloc(sizeof(ArcType*) * (*g)->num_vexs);

	for (i = 0; i < (*g)->num_vexs; i++) {
		(*g)->arc[i] = (ArcType*)malloc(sizeof(ArcType) * (*g)->num_vexs);
	}
}


void
createGraph(mgraph* g)
{
	int i, j;
	printf("��0��ʼ���ձ��˳�����붥��ֵ\n");
	for (int i = 0; i < g->num_vexs; i++) {
		scanf("%d", &g->vexs[i]);
	}
	getchar();
	printf("�����ڽӾ���, ����Ԫ��֮�䲻Ҫ�пո�, ��#���������\n");
	for (i = 0; i < g->num_vexs; i++) {
		for (j = 0; j < g->num_vexs; j++) {
			scanf("%c", &g->arc[i][j]);
		}
		getchar();
	}
}
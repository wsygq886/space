#include <stdio.h>
#include <stdlib.h>

typedef int  VertexType;	//顶点类型, 假定为int
typedef char ArcType;		//边的类型, 假定为char

typedef struct _mgraph {
    VertexType* vexs;   //顶点数一维组
    ArcType** arc;      //邻接矩阵
    int num_vexs;       //顶点数目
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

void initGraph(mgraph** g)
{
    int i;
    *g = (mgraph*)malloc(sizeof(mgraph));
    printf("输入顶点数\n");
    scanf("%d", &(*g)->num_vexs);

    (*g)->vexs = (VertexType*)malloc(sizeof(VertexType) * (*g)->num_vexs);

    (*g)->arc = (ArcType**)malloc(sizeof(ArcType*) * (*g)->num_vexs);       
    for (i = 0; i < (*g)->num_vexs; i++) {
        (*g)->arc[i] = (ArcType*)malloc(sizeof(ArcType) * (*g)->num_vexs);
    }
}


void createGraph(mgraph* g)
{
    int i, j;
    printf("从0开始按照编号顺序输入顶点值\n");
    for (int i = 0; i < g->num_vexs; i++) {
        scanf("%d", &g->vexs[i]);
    }
    getchar();
    printf("输入邻接矩阵, 矩阵元素之间不要有空格, 用#代替无穷大\n");
    for (i = 0; i < g->num_vexs; i++) {
        for (j = 0; j < g->num_vexs; j++) {
            scanf("%c", &g->arc[i][j]);
        }
        getchar();
    }
}
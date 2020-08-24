#include <stdio.h>
#include <stdlib.h>

typedef int  VertexType;//顶点类型 假定为int
typedef char ArcType;   //边的类型 假定为char

typedef struct _arcnode {
    int adjvex;         //邻接点下标
    int weight;	        //权重
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
    printf("输入顶点数\n");
    scanf("%d", &n);
    (*g)->num_vexs = n;
    (*g)->arr = (vertexnode*)malloc(sizeof(vertexnode) * n);
}

void createGraph(lgraph* g)
{
    int i;
    arcnode* p, * tail;
    printf("从0开始按照编号顺序输入顶点值\n");
    for (i = 0; i < g->num_vexs; i++) {
        scanf("%d", &g->arr[i].data);
    }
    getchar();
    printf("从0开始按照编号顺序输入邻接表, 所以输入数据都不要用空格分开, 输入#表示结束\n");
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


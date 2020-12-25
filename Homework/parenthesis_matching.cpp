#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Linear_List_Type {
	int list[100];
	int len;
}Linear_List_Type;

void InsertList(Linear_List_Type* p, int m, int i, int b);
void DeleteList(Linear_List_Type* p, int i);
void dispList(Linear_List_Type* p);

int main() {
	int i, n, c, x;
	int sum = 0;
	int mode;
	Linear_List_Type p;
	p.len = 0;
	scanf("%d", &x);
	scanf("%d", &n);
	for (i = 1; i <= n + 1; i++) {
		scanf("%d", &c);
		InsertList(&p, 100, i, c);
	}
	dispList(&p);
	scanf("%d", &mode);
	if (mode) {
		int o;
		do {
			int index;
			scanf("%d", &index);
			DeleteList(&p, index);
			scanf("%d", &c);
			InsertList(&p, m, index, c);
			dispList(&p);
			scanf("%d", &o);
		} while (o);
	}
	for (i = 0; i < p.len; i++) {
		sum += p.list[i] * pow(x, i);
	}
	printf("%d", sum);
	getchar();
	return 0;
}

void InsertList(Linear_List_Type* p, int m, int i, int b) {
	int k;
	if (p->len == m) {
		printf(" overflow!\n ");
		return;
	}
	if (i > p->len) {
		i = p->len + 1;
	}
	else if (i < 1)
		i = 1;
	for (k = p->len; k >= i; k--)
		p->list[k] = p->list[k - 1];
	p->list[i - 1] = b;
	p->len += 1;
}

void DeleteList(Linear_List_Type* p, int i) {
	int k;
	if (p->len == 0) {
		printf(" underflow !\n ");
		return;
	}
	if ((i < 1) || (i > p->len)) {
		printf(" This element is not in the list!\n ");
	}
	for (k = i; k < p->len; k++)
		p->list[k - 1] = p->list[k];
	p->len = p->len - 1;
	return;
}

void dispList(Linear_List_Type* p) {
	int i;
	for (i = 0; i < p->len; i++) {
		printf("%d %d", p->list[i], i);
	}
	printf("\n");
}
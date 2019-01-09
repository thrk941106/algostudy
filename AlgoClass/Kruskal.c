#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define INFINITY 99999
#define NIL -1
#define FALSE 0
#define	TRUE 1

//�Լ�����
void initial_parent(int* p, int vertex_number);
void weighted_union(int* p, int i, int j);
int find(int *p, int i);


int main(void) {
	//���� ����
	FILE *lf;
	// vertex, edge ���� ���� ����
	int vertex_number, edge_number;
	// �׷������� ���� ����
	int start, end, weight;
	// disjoint ���� ����
	int *F;
	int p, q;
	// ��Ÿ ����
	int i;
	
	//input���� vertex,edge ���� �о����
	fopen_s(&lf, "input1.txt", "r");
	fscanf(lf, "%d %d", &vertex_number, &edge_number);

	//�ʿ� List, Array ����, �����Ҵ�, �ʱ�ȭ
	F= (int*)calloc(vertex_number + 1, sizeof(int));
	initial_parent(F, vertex_number);

	for (i = 0; i < edge_number; i++) {
		fscanf_s(lf, "%d %d %d", &start, &end, &weight);
		if ((p = find(F, start) ) != (q= find(F, end))) {
			weighted_union(F ,p, q);
			printf("%d %d %d\n", start, end, weight);
		}
	}
	system("pause");
}



void initial_parent(int* p, int vertex_number) {
	int i;
	for (i = 0; i <= vertex_number; i++) {
		p[i] = NIL;
	}
}

void weighted_union(int* p, int i, int j) {
	int temp = p[i] + p[j];
	if (p[i] > p[j]) {
		p[i] = j;
		p[j] = temp;
	}
	else {
		p[j] = i;
		p[i] = temp;
	}
}

int find(int *p, int i) {
	int r, s;
	for (r = i; p[r] >= 0; r = p[r]);

	while (i != r) {
		s = p[i];
		p[i] = r;
		i = s;
	}
	return r;
}
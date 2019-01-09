#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define INFINITY 99999
#define NIL -1
#define FALSE 0
#define	TRUE 1

//함수선언
void initial_parent(int* p, int vertex_number);
void weighted_union(int* p, int i, int j);
int find(int *p, int i);


int main(void) {
	//파일 변수
	FILE *lf;
	// vertex, edge 갯수 저장 변수
	int vertex_number, edge_number;
	// 그래프정보 저장 변수
	int start, end, weight;
	// disjoint 연산 변수
	int *F;
	int p, q;
	// 기타 변수
	int i;
	
	//input에서 vertex,edge 갯수 읽어오기
	fopen_s(&lf, "input1.txt", "r");
	fscanf(lf, "%d %d", &vertex_number, &edge_number);

	//필요 List, Array 생성, 동적할당, 초기화
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
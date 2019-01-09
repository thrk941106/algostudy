#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define INFINITY 99999
#define NIL -1
#define FALSE 0
#define	TRUE 1

//�Լ�����
void weighted_union(int* p, int* R, int i, int j);
int find(int *p, int *R, int i);


int main(void) {
	//���� ����
	FILE *lf;
	// vertex, edge ���� ���� ����
	int job_number;
	// �׷������� ���� ����
	int job, deadline, profit;
	// disjoint ���� ����
	int *F;
	int *real_input;
	int *job_list;
	int p, q, temp;
	// ��Ÿ ����
	int i;

	//input���� vertex,edge ���� �о����
	fopen_s(&lf, "input1.txt", "r");
	fscanf(lf, "%d", &job_number);

	//�ʿ� List, Array ����, �����Ҵ�, �ʱ�ȭ
	F = (int*)calloc(job_number + 1, sizeof(int));
	real_input = (int*)calloc(job_number + 1, sizeof(int));
	for (i = 1; i <= job_number; i++) {
		F[i] = NIL;
		real_input[i] = i;
	}
	F[0] = job_number;
	
	job_list = (int*)calloc(job_number + 1, sizeof(int));

	for (i = 0; i < job_number; i++) {
		fscanf_s(lf, "%d %d %d", &job, &deadline, &profit);

		p = (find(F, real_input, deadline));
		temp = real_input[p];
		q = (find(F, real_input, temp - 1));
		weighted_union(F, real_input, p, q);
		job_list[temp] = job;
	}
	for (i = 1; i <= job_number; i++) {
		printf("%d ", job_list[i]);
	}
	printf("\n");
	system("pause");
}

void weighted_union(int* p, int* R, int i, int j) {
	int temp = p[i] + p[j];
	if ( p[j] < p[i]) {
		p[i] = j;
		p[j] = temp;
	}
	else {
		p[j] = i;
		p[i] = temp;
	}
	R[i] = R[j];
}


int find(int *p, int *R, int i) {
	int r, s;
	for (r = i; p[r] >= 0; r = p[r]);
	while (i != r) {
		s = p[i];
		p[i] = r;
		i = s;
	}
	return r;
}
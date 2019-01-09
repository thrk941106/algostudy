#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INFINITY 99999
#define NIL 0

int *d;
int *p;
int *ans;
void BELLMAN_FORD(int center_number, int* center_checktime, int* center_distance, int maximum_drive);
void INITIALIZE_SINGLE_SOURCE(int center_number);
void RELAX(int u, int v, int* center_checktime);

int main(void) {
	//파일 변수
	FILE *f;
	int maximum_drive;
	int center_number;
	int* center_distance;
	int* center_checktime;
	int i,j=0;
	int size=0, time=0;

	// 파일열기
	fopen_s(&f, "input.txt", "r");
	//input에서 block 갯수 읽어오기
	fscanf_s(f, "%d%*c", &maximum_drive);
	fscanf_s(f, "%d%*c", &center_number);
	p = (int*)calloc(center_number + 3, sizeof(int));
	ans = (int*)calloc(center_number + 1, sizeof(int));
	d = (int*)calloc(center_number + 3, sizeof(int));
	center_distance = (int*)calloc(center_number + 3, sizeof(int));
	center_checktime = (int*)calloc(center_number + 3, sizeof(int));



	//블락정보 저장 및 초기화
	for (i = 1; i <= center_number+1; i++) {
			fscanf_s(f, "%d", &center_distance[i]);
	}
	for (i = 1; i <= center_number; i++) {
		fscanf_s(f, "%d", &center_checktime[i]);
	}
	BELLMAN_FORD(center_number, center_checktime,center_distance, maximum_drive);

	for (i = center_number + 1; p[i] >0;) {
		time = time + center_checktime[p[i]];
		ans[j++] = p[i];
		i = p[i];
		size++;
	}
	printf("정비 시간 : %d\n", time);
	printf("정비장 수 : %d\n", size);
	printf("정비장 : ");
	for (i = size - 1; i >= 0; i--) {
		printf("%d ", ans[i]);
	}
	system("pause");


}



void BELLMAN_FORD(int center_number, int* center_checktime, int* center_distance,int maximum_drive) {
	int max = 0;
	int i,j,k;
	int distance = 0;
	int check=0;
	INITIALIZE_SINGLE_SOURCE(center_number);

	for (i = 0; i <= center_number;i++) {
		for (j = i+1; j<=center_number+1 && check<=0; j++) {
			for (k = i+1; k <= j ; k++) {
				distance = distance + center_distance[k];
			}
			if (distance > maximum_drive) {
				check=3;
			}
			else {
				RELAX(i, j, center_checktime);
			}
			distance = 0;
		}
		check = 0;
	}
}

void RELAX(int u, int v, int* center_checktime) {
	int W=0;
	int i;
	for (i = u; i <= v; i++) {
		W = W + center_checktime[i];
	}
	if (d[v] >= d[u] + W) {
		d[v] = d[u] + W;
		p[v] = u;
	}
}

void INITIALIZE_SINGLE_SOURCE(int center_number) {
	int i;
	int n=0;

	for (i = 0; i <= center_number + 1; i++) {
		d[i] = INFINITY;
		p[i] = NIL;
	}
	d[0] = 0;
}
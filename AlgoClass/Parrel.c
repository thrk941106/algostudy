#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<malloc.h>
void sort_last();
void sort_vert();
void sort_hor();
void print();
FILE *lf;
int n;
int **computers;
int main() {
	int i,j, k;
	int s;
	int temp;
	s = (log((double)n) / log((double)2));

	fopen_s(&lf,"input.txt","r");
	fscanf(lf, "%d", &n);
	computers = (int**)calloc(n+1, sizeof(int*));
	for (i = 1; i <= n; i++) {
		computers[i] = (int*)calloc(n + 1, sizeof(int));
		for (j = 1; j <= n; j++) {
			fscanf(lf, "%d",&computers[i][j]);
		}
	}
	print();
	printf("\n\n");
	for (i = 1; i < n; i=i*2) {
		sort_hor();
		sort_vert();
	}
	sort_last();
	print();

	system("pause");

}

void sort_vert() {
	int i, j, k, temp;
	for (j = 1; j <= n; j++) {
			for (k = 0; k < n/2; k++) {
				for (i = 1; i < n; i = i + 2) {
					temp = computers[i+1][j];
					if (temp < computers[i][j])
					{
						computers[i+1][j] = computers[i][j];
						computers[i][j] = temp;
					}
				}
				for (i = 2; i < n; i = i + 2) {
					temp = computers[i+1][j];
					if (temp < computers[i][j])
					{
						computers[i+1][j] = computers[i][j];
						computers[i][j] = temp;
					}
				}
			}
	}
}

void sort_hor() {
	int i, j, k, temp;
	for (i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (k = 0; k < n/2; k++) {
				for (j = 1; j < n; j = j + 2) {
					temp = computers[i][j + 1];
					if (temp < computers[i][j])
					{
						computers[i][j + 1] = computers[i][j];
						computers[i][j] = temp;
					}
				}
				for (j = 2; j < n; j = j + 2) {
					temp = computers[i][j + 1];
					if (temp < computers[i][j])
					{
						computers[i][j + 1] = computers[i][j];
						computers[i][j] = temp;
					}
				}
			}
		}
		else {
			for (k = 0; k < n; k++) {
				for (j = 1; j < n; j = j + 2) {
					temp = computers[i][j + 1];
					if (temp > computers[i][j])
					{
						computers[i][j + 1] = computers[i][j];
						computers[i][j] = temp;
					}
				}
				for (j = 2; j < n; j = j + 2) {
					temp = computers[i][j + 1];
					if (temp > computers[i][j])
					{
						computers[i][j + 1] = computers[i][j];
						computers[i][j] = temp;
					}
				}
			}
		}
	}
}


void sort_last() {
	int i, j, k, temp;
	for (i = 1; i <= n; i++) {
			for (k = 0; k < n; k++) {
				for (j = 1; j < n; j = j + 2) {
					temp = computers[i][j + 1];
					if (temp < computers[i][j])
					{
						computers[i][j + 1] = computers[i][j];
						computers[i][j] = temp;
					}
				}
				for (j = 2; j < n; j = j + 2) {
					temp = computers[i][j + 1];
					if (temp < computers[i][j])
					{
						computers[i][j + 1] = computers[i][j];
						computers[i][j] = temp;
					}
				}
			}
	}
}

void print() {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", computers[i][j]);
		}
		printf("\n");
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void bin_packing(int n, int object);
void intitialize(int n, int bin_capacity);
int* tree;
int* player;

int main() {
	FILE *lf;
	int k;
	int bin_capacity, object_number, n;
	int p;
	int i;
	int object;
	fopen_s(&lf, "input2.txt", "r");
	fscanf_s(lf, "%d %d %d", &bin_capacity, &object_number, &n);

	player = (int*)calloc(n + 1, sizeof(int));
	tree = (int*)calloc(n, sizeof(int));

	intitialize(n, bin_capacity);
	for (i = 1; i <= object_number; i++) {
		fscanf_s(lf, "%d", &object);

		if (player[tree[1]] >= object) {
			bin_packing(n, object);
		}
	}
	for (i = 1; i <= n; i++) {
		printf("%d ", player[i]);
	}
	system("pause");

}

void intitialize(int n, int bin_capacity) {
	int k;
	int p;

	for (k = 1; k <= n; k++) {
		player[k] = bin_capacity;
	}
	for (k = 1; k <= n; k = k + 2) {
		p = (k + n - 1) / 2;
		tree[p] = k;
	}
	for (k = (n - 1) / 2; k > 0; k--)
		tree[k] = tree[k * 2];
}

void bin_packing(int n, int object) {

	int k, p;

	for (k = 2; k < n; k = k * 2) {
		if (player[tree[k]] < object) {
			k++;
			if (player[tree[k]] < object) {
				break;
			}
			else {
				continue;
			}
		}
	}

	if (k >= n) {
		k = k / 2;
		p = tree[k];
		if (p % 2 == 0 && player[p - 1] >= object) {
			player[p - 1] -= object;
		}
		else player[p] -= object;
		if (p % 2 == 1) {
			if (player[p] < player[p + 1]) {
				tree[k] = p + 1;
			}
		}
		else {
			if (player[p] < player[p - 1]) {
				tree[k] = p - 1;
			}
		}
		for (k /= 2; k >= 1; k /= 2) {
			if (player[tree[k * 2]] >= player[tree[k * 2 + 1]])
				tree[k] = tree[k * 2];
			else
				tree[k] = tree[k * 2 + 1];
		}
	}
}
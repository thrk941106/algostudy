#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>

void bin_packing(int n, int object);
void intitialize(int n, int bin_capacity);
int* tree;
int* player;
int LowExt;

int main() {
	FILE *lf;
	int k;
	int bin_capacity, object_number, n;
	int p;
	int i;
	int object;
	fopen_s(&lf, "input.txt", "r");
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
	int s;
	int offset;
	s = pow(2, ceil(log((double)n) / log((double)2)) - 1);
	offset = 2 * s - 1;
	LowExt = 2 * ((n - 1) - (s - 1));

	for (k = 1; k <= n; k++) {
		player[k] = bin_capacity;
	}
	for (k = 1; k <= LowExt; k = k + 2) {
		p = (k + offset) / 2;
		tree[p] = k;
	}
	for (k = LowExt; k <= n; k = k + 2) {
		p = (k - LowExt + n - 1) / 2;
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

			//추가된 부분
			if (k > n - 1) {
				continue;
			}
			//--
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
		
		//추가된 것	
		if (k > n - 1) {
			k = k / 2;
		}
		//--
		p = tree[k];
		if (p % 2 == 0 && player[p - 1] >= object) {
			player[p - 1] -= object;
		}
		else player[p] -= object;
	
		//추가된 것
		if (p == LowExt+1 && n % 2 == 1) {
			if(player[p] < player[tree[n - 1]]){
				tree[k] = tree[n - 1];
			}
		}
		//--
		else if (p % 2 == 1) {
			if (p <= LowExt) {
				if (player[p] < player[p + 1]) {
					tree[k] = p + 1;
				}
			}

			//추가된부분
			else {
				if (player[p] < player[p - 1]) {
					tree[k] = p - 1;
				}
			}
			//--
		}
		else {
			if (p <= LowExt) {
				if (player[p] < player[p - 1]) {
					tree[k] = p - 1;
				}
			}

			//추가된부분
			else {
				if (player[p] < player[p + 1]) {
					tree[k] = p + 1;
				}
			}
			//--
		}

		for (k /= 2; k >= 1; k /= 2) {
			//추가된것
			if (k * 2  == n - 1) {
				if (player[tree[k*2]] >= player[LowExt + 1]) {
					tree[k] = tree[k*2];
				}
				else
					tree[k] = LowExt + 1;
				continue;
			}
			//--
			else if (player[tree[k * 2]] >= player[tree[k * 2 + 1]])
				tree[k] = tree[k * 2];
			else
				tree[k] = tree[k * 2 + 1];
		}
	}
}
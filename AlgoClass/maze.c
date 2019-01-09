#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define INFINITY 99999
#define NIL -1
#define FALSE 0
#define	TRUE 1

#define right 1
#define down 2
#define left 3
#define up 4



typedef struct {
	int x;
	int y;
	int distance;
} tHeap;

int cnt=0;
int **d;
int **p;
int **flag;
int **graph;
int heapsize = 0;
int breakcount = 0;
tHeap *PQ;
void initial_array(FILE *lf, int n);
void print_path(int i,int j);
void siftdown(int i);
void insert_heap(int x, int y, int distance);
tHeap EXTRACT_MIN();
void Dijkstra(int n);


int main() {
	FILE *lf;
	int n;
	fopen_s(&lf, "input.txt", "r");
	fscanf(lf, "%d*", &n);
	initial_array(lf,n);
	Dijkstra(n);
	print_path(n,n);
	printf("Break block : %d\n", d[n][n]);
	system("pause");
}

void Dijkstra(int n)
{
	int check;
	int i, j;
	int dis;
	tHeap u;
	insert_heap(1, 1, 0);
	while (heapsize != 0 && d[n][n] == INFINITY) {
		u = EXTRACT_MIN(PQ);
		i = u.x;
		j = u.y;
		if (flag[i][j] == 0) {

			//아래로 가기
			if (i < n) {
				if (flag[i + 1][j] == 0) {
					if (graph[i + 1][j] == 0) {
						dis = 1;
					}
					else if (graph[i + 1][j] == 1) {
						dis = 0;
					}
					if (d[i + 1][j] > dis + d[i][j]) {
						p[i + 1][j] = up;
						d[i + 1][j] = dis + d[i][j];
						insert_heap(i + 1, j, d[i + 1][j]);
					}
				}
			}

			//오른쪽으로 가기
			if (j < n) {
				if (flag[i][j + 1] == 0) {
					if (graph[i][j + 1] == 0) {
						dis = 1;
					}
					else if (graph[i][j + 1] == 1) {
						dis = 0;
					}
					if (d[i][j + 1] > dis + d[i][j]) {
						p[i][j + 1] = left;
						d[i][j + 1] = dis + d[i][j];
						insert_heap(i, j + 1, d[i][j + 1]);
					}
				}
			}

			//위로 가기
			if (i > 1) {
				if (flag[i-1][j]==0) {
					if (graph[i - 1][j] == 0) {
						dis = 1;
					}
					else if (graph[i - 1][j] == 1) {
						dis = 0;
					}
					if (d[i - 1][j] > dis + d[i][j]) {
						p[i - 1][j] = down;
						d[i - 1][j] = dis + d[i][j];
						insert_heap(i - 1, j, d[i - 1][j]);
					}
				}
			}

			//왼쪽으로 가기
			if (j > 1) {
				if (flag[i][j - 1]==0) {
					if (graph[i][j - 1] == 0) {
						dis = 1;
					}
					else if (graph[i][j - 1] == 1) {
						dis = 0;
					}
					if (d[i][j - 1] > dis + d[i][j]) {
						p[i][j - 1] = right;
						d[i][j - 1] = dis + d[i][j];
						insert_heap(i, j - 1, d[i][j - 1]);
					}
				}
			}
		}
	}
}

void initial_array(FILE *lf , int n) {
	int i, j;
	char c;
	int room;
	fgetc(lf);
	d = (int**)calloc(n + 1, sizeof(int*));
	p = (int**)calloc(n + 1, sizeof(int*));
	flag = (int**)calloc(n + 1, sizeof(int*));
	PQ = (tHeap *)calloc((n + 1)*(n+1), sizeof(tHeap));
	graph = (int**)calloc(n + 1, sizeof(int*));
	for (i = 1; i <= n; i++) {
		d[i] = (int*)calloc(n + 1, sizeof(int));
		p[i]= (int*)calloc(n + 1, sizeof(int));
		flag[i] = (int*)calloc(n + 1, sizeof(int));
		graph[i] = (int*)calloc(n + 1, sizeof(int));
		for (j = 1; j <= n; j++) {
			d[i][j] = INFINITY;
			p[i][j] = NIL;
			if (i == 0 || j == 0) {
				graph[i][j] = NIL;
			}
			else {
				c=fgetc(lf);
				room = c - '0';
				graph[i][j] = room;
				if (j == n) {
					fgetc(lf);
				}
			}
		}
	}
	d[1][1] = 0;
}

void print_path(int i, int j) {
	int t;
	t = p[i][j];
	if (t == up)
		print_path(i - 1, j);
	else if (t == right)
		print_path(i, j + 1);
	else if (t == down)
		print_path(i + 1, j);
	else if (t == left)
		print_path(i, j - 1);
	if (cnt > 10) {
		cnt = 0;
		printf("\n");
	}
	printf("%d %d -> ", i, j);
	cnt++;

}



void siftdown(int i) {
	int siftkey_x = PQ[i].x, siftkey_y = PQ[i].y, siftkey_distance = PQ[i].distance, parent = i, found = 0;
	int smaller_child;

	while (2 * parent <= heapsize && found == 0) {
		if (2 * parent < heapsize && PQ[2 * parent].distance >= PQ[2 * parent + 1].distance)
			smaller_child = 2 * parent + 1;
		else
			smaller_child = 2 * parent;
		if (siftkey_distance > PQ[smaller_child].distance) {
			PQ[parent] = PQ[smaller_child];
			parent = smaller_child;
		}
		else
			found = 1;
	}
	PQ[parent].x = siftkey_x;
	PQ[parent].y = siftkey_y;
	PQ[parent].distance = siftkey_distance;
}

tHeap EXTRACT_MIN() {
	tHeap root = PQ[1];
	tHeap result = root;
	PQ[1] = PQ[heapsize];
	heapsize--;
	siftdown(1);
	return result;
}

void insert_heap(int x, int y, int distance)
{
	int parent = ++heapsize / 2;
	int index = heapsize;
	while (parent > 0 && distance < PQ[parent].distance) {
		PQ[index] = PQ[parent];
		index = parent;
		parent /= 2;
	}

	PQ[index].x = x;
	PQ[index].y = y;
	PQ[index].distance = distance;

}
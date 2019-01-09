#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INFINITY 99999
#define NIL -1

//±¸Á¶Ã¼ Á¤ÀÇ
typedef struct node {
	int x;
	int y;
	struct node* next;
}node;

typedef struct Queue {
	node* first;
	node* rear;
}Queue;

Queue queue;
typedef struct {
	short int vert;
	short int horiz;
}offsets;
offsets move[4] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };

int eating_count = 0;
int tx, ty;
int size = 2;
int x, y;
int time = 0;


int **color;
int **p;
int **d;
int **graph;


void alloc_arr(FILE *lf, int n);
void DEQUEUE();
void ENQUEUE(int x, int y);
void ini_all(int n);
void BFS(int n);



int main() {
	FILE *lf;
	int n;
	fopen_s(&lf, "input.txt", "r");
	fscanf(lf, "%d*", &n);
	fscanf(lf, "%d %d*", &x, &y);
	alloc_arr(lf, n);

	while (x >= 0 && y >= 0)
	{
		queue.first = NULL;
		queue.rear = NULL;

		BFS(n);
		if (queue.first == NULL) {
			break;
		}
		time = time + d[tx][ty];
		printf("source : (%d %d)      destination : (%d, %d)   ÃÑ Å½Çè½Ã°£%d\n", x, y, tx, ty, time);
		x = tx;
		y = ty;
	}
	system("pause");
}

void alloc_arr(FILE *lf, int n) {
	int i, j;
	char c;
	int room;
	p = (int**)malloc(sizeof(int*)*(n + 1));
	d = (int**)malloc(sizeof(int*)*(n + 1));
	color = (int**)malloc(sizeof(int*)*(n + 1));
	graph = (int**)malloc(sizeof(int*)*(n + 1));
	fgetc(lf);
	for (i = 0; i < n; i++)
	{
		p[i] = (int*)malloc(sizeof(int)*(n + 1));
		d[i] = (int*)malloc(sizeof(int)*(n + 1));
		color[i] = (int*)malloc(sizeof(int)*(n + 1));
		graph[i] = (int*)malloc(sizeof(int)*(n + 1));
		for (j = 0; j < n; j++) {
				c = fgetc(lf);
				room = c - '0';
				graph[i][j] = room;
				if (j == n-1) {
					fgetc(lf);
				}
			
		}
	}

}
void ENQUEUE(int x, int y) {
	node *temp;
	temp = (node*)calloc(1, sizeof(node));
	temp->x = x;
	temp->y = y;
	if (queue.first == NULL) {
		queue.first = temp;
		queue.rear = temp;
	}
	else {
		queue.rear->next = temp;
		queue.rear = temp;
	}
}

void DEQUEUE() {
	node *temp;
	temp = queue.first;
	queue.first = queue.first->next;
	free(temp);
}
void ini_all(int n) {
	int i, j;
	for (i = 0; i <n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			color[i][j] = WHITE;
			d[i][j] = INFINITY;
			p[i][j] = NIL;
		}

	}
	color[x][y] = GRAY;
	d[x][y] = 0;
	p[x][y] = NIL;

}


void BFS(int n) {
	int i, j, k;
	int temp_x, temp_y;

	ini_all(n);

	ENQUEUE(x, y);

	while (queue.first != NULL)
	{
		i = queue.first->x;
		j = queue.first->y;
		for (k = 0; k<4; k++) {
			temp_x = i + move[k].vert;
			temp_y = j + move[k].horiz;
			if ((temp_x >= 0 && temp_x < n) && (temp_y >= 0 && temp_y < n) && graph[temp_x][temp_y] <= size)
			{
				if (color[temp_x][temp_y] == WHITE)
				{
					if (graph[temp_x][temp_y] != 0 && graph[temp_x][temp_y] < size)
					{
						eating_count++;
						if (eating_count == size)
						{
							size++;
							eating_count = 0;
						}
						graph[temp_x][temp_y] = 0;
						d[temp_x][temp_y] = d[i][j] + 1;
						tx = temp_x;
						ty = temp_y;
						return;
					}
					color[temp_x][temp_y] = GRAY;
					d[temp_x][temp_y] = d[i][j] + 1;
					p[temp_x][temp_y] = k;
					ENQUEUE(temp_x, temp_y);
				}
			}
		}
		DEQUEUE();
		color[i][j] = BLACK;
	}
}
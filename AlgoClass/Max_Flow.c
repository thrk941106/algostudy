#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INFINITY 99999
#define NIL -1


//구조체 정의
typedef struct node {
	int vertex;
	int capacity;
	int flow;
	struct node* pair;
	struct node* next;
	struct node* for_path;
}node;

typedef struct Queue {
	node* first;
	node* rear;
}Queue;

typedef struct root {
	node* first_node;
	node* last_node;
}root;

//전역변수
//root *list;
Queue queue;
Queue path;
int *color;
int *d;

//함수선언
void initList(root* list, node* temp, int start, int capacity);
void BFS(root* list, int vertex_number, int* p);
void DEQUEUE();
void ENQUEUE(int data);
void addpath(root* list, int vertex_number, int* p);
void ADDPATHQ(node* temp);
void DEPATHQ();

int main(void) {
	//파일 변수
	FILE *f;
	FILE *lf, *lfout;
	// vertex, edge 갯수 저장 변수
	int vertex_number, edge_number;
	// 그래프정보 저장 변수
	int start, end, capacity;
	// DFS Tree 배열
	int *p;
	// list 읽기용 temp 변수
	node* temp;
	node* temp2;
	// 기타 변수
	int i, j;
	int ans=0;

	int num;
	root *load;
	root *list;
	//load input
	int load_num;
	int** sq;
	//int* wh1;
	int nod_num;
	int how1=0;
	char a;
	fopen_s(&lf, "linput.txt", "r");
	fscanf(lf, "%d", &load_num);
	vertex_number = load_num * load_num * 2;
	edge_number = vertex_number/2 + ((load_num - 1)*load_num * 2) * 2 + (load_num - 1) * 4;
	
	load = (root*)calloc(vertex_number + 2, sizeof(root));
	sq= (int**)calloc(load_num+1, sizeof(int*));
	fscanf(lf, "%c", &a);
	for (i = 1; i <= load_num ; i++) {
		sq[i] = (int*)calloc(load_num+1 , sizeof(int));
		for (j = 1; j <= load_num ; j++) {
			fscanf(lf, "%c", &a);
			if (a == '1') {
				sq[i][j] = 1;
			}
			else if (a == '0') {
				sq[i][j] = 0;
			}
			if (sq[i][j] == 1) {
				how1++;
			}
		}
		fscanf(lf, "%c", &a);
	}
	printf("start %d ",how1);
	edge_number = edge_number + how1;
	fopen_s(&lfout, "loutput.txt", "w");
	fprintf(lfout, "%d %d\n", vertex_number, edge_number);
 
	for (i = 1; i <= load_num; i++) {
		for (j = 1; j <= load_num; j++) {
			nod_num = (((i - 1)*load_num) + j);
			if (sq[i][j] == 1) {
				fprintf(lfout, "0 %d 1\n", nod_num *2 - 1);
			}
		
			fprintf(lfout, "%d %d 1\n", 2 * nod_num - 1, 2 * nod_num);
			
			if (i - 1 > 0) {
				fprintf(lfout, "%d %d 1\n", 2 * nod_num, 2 * nod_num - 1 - (load_num * 2));
			}
			if (i + 1 <= load_num) {
				fprintf(lfout, "%d %d 1\n", 2 * nod_num, 2 * nod_num - 1 + (load_num * 2));
			}

			if (j - 1 > 0) {
				fprintf(lfout, "%d %d 1\n", 2 * nod_num, 2 * nod_num - 1-2);
			}
			if (j + 1 <= load_num) {
				fprintf(lfout, "%d %d 1\n", 2 * nod_num, 2 * nod_num - 1 + 2);
			}

			if (i == 1 || i == load_num) {
				fprintf(lfout, "%d %d 1\n", 2 * nod_num , vertex_number + 1);
			}
			else if (j == 1 || j == load_num) {
				fprintf(lfout, "%d %d 1\n", 2 * nod_num , vertex_number + 1);
			}

		}

	}
	fclose(lfout);

	// 파일열기

	fopen_s(&f, "loutput.txt", "r");

	//input에서 vertex,edge 갯수 읽어오기
	fscanf_s(f, "%d %d", &vertex_number, &edge_number);

	//필요 List, Array 생성 및 동적할당
	list = (root*)calloc(vertex_number + 2, sizeof(root));
	queue.first = NULL;
	queue.rear = NULL;
	p = (int*)calloc(vertex_number + 1, sizeof(int));
	d = (int*)calloc(vertex_number + 1, sizeof(int));
	color = (int*)calloc(vertex_number + 1, sizeof(int));

	// input 에서 값 읽어서 그래프를 AdjList 만들기
	for (i = 0; i < edge_number; i++) {
		temp = (node*)calloc(1, sizeof(node));
		temp2 = (node*)calloc(1, sizeof(node));
		fscanf_s(f, "%d %d %d", &start, &end, &capacity);
		temp->vertex = end;
		temp->capacity = capacity;
		temp2->vertex = start;
		temp2->capacity = 0;
		temp->pair = temp2;
		temp2->pair = temp;
		initList(list, temp, start, capacity);
		initList(list, temp2, end, capacity);
	}
	/*
	BFS(vertex_number, p);
	addpath(vertex_number, p);
	*/
	while (1){//(p[vertex_number + 1] != NIL) {
		BFS(list, vertex_number, p);
		if (p[vertex_number + 1] == NIL) {
			break;
		}
		addpath(list, vertex_number, p);
	}

	for (temp = list[0].first_node; temp; temp = temp->next) {
		//printf("%d\n", temp->flow);
		ans = ans + (temp->flow);
	}
	if (ans == how1) {
		printf("=");
		printf("Max : %d\n", ans);
		printf("escape success!\n");
	}
	else if (ans != how1) {
		printf("!=");
		printf("Max : %d\n", ans);
		printf("escape false\n");
	}
	free(list);
	fclose(f);
	system("pause");
}


// 리스트생성함수
void initList(root* list, node* temp, int start, int capacity) {
	node *check;
	int n = temp->vertex;
	if (list[start].first_node == NULL)
		list[start].first_node = temp;
	else {
		for (check = list[start].first_node; check; check = check->next) {
			if (check->vertex == n) {
				if (check->capacity == 0) {
					check->capacity = capacity;
				}

				return;
			}
		}
		list[start].last_node->next = temp;
	}
	list[start].last_node = temp;
}

void ENQUEUE(int data) {
	node *temp;
	temp = (node*)calloc(1, sizeof(node));
	temp->vertex = data;
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
void DEPATHQ() {
	path.first = NULL;
	path.rear = NULL; 
}

void ADDPATHQ(node* temp) {
	if (path.rear == NULL) {
		path.first = temp;
		path.rear = temp;
	}
	else {
		temp->for_path = path.first;
		path.first = temp;
	}

}

void BFS(root* list, int vertex_number, int* p) {
	node *u;
	node *v;
	for (int i = 0; i <= vertex_number + 1; i++) {
		color[i] = WHITE;
		d[i] = INFINITY;
		p[i] = NIL;
	}
	color[0] = GRAY;
	d[0] = 0;
	ENQUEUE(0);

	while (queue.first != NULL) {
		u = queue.first;
		for (v = list[u->vertex].first_node; v; v = v->next) {
			if (v->capacity - v->flow <= 0) {
				continue;
			}
			else if (color[v->vertex] == WHITE) {
				color[v->vertex] = GRAY;
				d[v->vertex] = d[u->vertex] + 1;
				p[v->vertex] = u->vertex;
				ENQUEUE(v->vertex);
			}
			//도착지에 오면 처리후 끝내기
			if (v->vertex == vertex_number + 1) {
				color[u->vertex] = BLACK;
				queue.first = NULL;
				queue.rear = NULL;
				return;
			}
		}
		color[u->vertex] = BLACK;
		DEQUEUE();
	}
}

void addpath(root* list, int vertex_number, int* p) {
	int i;
	int small;
	node* temp;

	for (i = vertex_number + 1; i != 0;) {
		for (temp = list[p[i]].first_node; temp; temp = temp->next) {
			if (temp->vertex == i) {
				ADDPATHQ(temp);
				break;
			}
		}
		i = p[i];
	}
	small = INFINITY;
	for (temp = path.first; temp!= NULL; temp = temp->for_path) {
		if (small > (temp->capacity)-(temp->flow)) {
			small = (temp->capacity) - (temp->flow);
		}
	}
	for (temp = path.first; temp!=NULL; temp = temp->for_path) {
		temp->flow = temp->flow + small;
		temp->pair->flow = (-1)*(temp->flow);
	}

	DEPATHQ();
}
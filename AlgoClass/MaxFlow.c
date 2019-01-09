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
root *list;
Queue queue;
Queue path;
int *color;
int *d;

//함수선언
void initList(node* temp, int start, int capacity);
void BFS(int vertex_number, int* p);
void DEQUEUE();
void ENQUEUE(int data);
void addpath(int vertex_number, int* p);
void ADDPATHQ(node* temp);
void DEPATHQ();

int main(void) {
	//파일 변수
	FILE *f;
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
	int i;


	// 파일열기

	fopen_s(&f, "input.txt", "r");

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
		fscanf_s(f, "%d %d %d", &start, &end,&capacity);
		temp->vertex = end;
		temp->capacity = capacity;
		temp2->vertex = start;
		temp2->capacity = 0;
		temp->pair = temp2;
		temp2->pair = temp;
		initList(temp, start, capacity);
		initList(temp2, end, capacity);
	}
	
	// Adjlist 출력하기
	for (i = 0; i <= vertex_number+1; i++) {
		printf("%d ", i);
		if (list[i].first_node == NULL) {
			printf("\n");
			continue;
		}
		for (temp = list[i].first_node; temp; temp = temp->next) {
			printf("(%d %d %d pair (%d,%d)) ", temp->vertex, temp->capacity, temp->flow, temp->pair->pair->vertex,temp->pair->vertex);
		}
		printf("\n");
	}


	BFS(vertex_number, p);

	printf("BFS : ");
	for (i = 0; i <= vertex_number+1; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");

	addpath(vertex_number, p);
	printf("\n");
	for (i = 0; i <= vertex_number + 1; i++) {
		printf("%d ", i);
		if (list[i].first_node == NULL) {
			printf("\n");
			continue;
		}
		for (temp = list[i].first_node; temp; temp = temp->next) {
			printf("(%d %d %d pair (%d,%d)) ", temp->vertex, temp->capacity, temp->flow, temp->pair->pair->vertex, temp->pair->vertex);
		}
		printf("\n");
	}
	printf("\n");
	while (p[vertex_number + 1] != NIL) {
		BFS(vertex_number, p);
		//printf("%df", p[vertex_number + 1]);
		//printf("BFS\n");
		if (p[vertex_number + 1] == NIL) {
			break;
		}
		addpath(vertex_number, p);
		printf("\n");
		for (i = 0; i <= vertex_number + 1; i++) {
			printf("%d ", i);
			if (list[i].first_node == NULL) {
				printf("\n");
				continue;
			}
			for (temp = list[i].first_node; temp; temp = temp->next) {
				printf("(%d %d %d pair (%d,%d)) ", temp->vertex, temp->capacity, temp->flow, temp->pair->pair->vertex, temp->pair->vertex);
			}
			printf("\n");
		}
		printf("\n");
		//printf("addpath\n");
	}
	printf("\n");
	for (i = 0; i <= vertex_number + 1; i++) {
		printf("%d ", i);
		if (list[i].first_node == NULL) {
			printf("\n");
			continue;
		}
		for (temp = list[i].first_node; temp; temp = temp->next) {
			printf("(%d %d %d pair (%d,%d)) ", temp->vertex, temp->capacity, temp->flow, temp->pair->pair->vertex, temp->pair->vertex);
		}
		printf("\n");
	}
	printf("\n");

	free(list);
	fclose(f);
	system("pause");
}


// 리스트생성함수
void initList(node* temp, int start, int capacity) {
	node *check;
	int n = temp->vertex;
	if (list[start].first_node == NULL)
		list[start].first_node = temp;
	else {
		for (check = list[start].first_node; check; check = check->next) {
			if (check->vertex == n) {
				if(check->capacity==0) {
					check->capacity = capacity;
				}

				return ;
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
	node *temp;
	path.first = NULL;
	path.rear = NULL;
}

void ADDPATHQ(node* temp) {
	node *temp2;
	temp2 = (node*)calloc(1, sizeof(node));
	if (path.rear == NULL) {
		path.first = temp;
		path.rear = temp;
	}
	else {
		temp2->capacity = temp->capacity;
		temp2->flow = temp->flow;
		temp2->pair = temp->pair;
		temp2->vertex = temp->vertex;
		temp2->next = path.first;
		path.first = temp2;
	}

}

void BFS(int vertex_number, int* p) {
	node *u;
	node *v;
	for (int i = 0; i <= vertex_number+1; i++) {
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
			if (v->capacity-v->flow <= 0) { continue; }
			if (color[v->vertex] == WHITE) {
				color[v->vertex] = GRAY;
				d[v->vertex] = d[u->vertex] + 1;
				p[v->vertex] = u->vertex;
				ENQUEUE(v->vertex);
			}
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

void addpath(int vertex_number, int* p) {
	int i;
	int small;
	node* temp;

	for (int i = vertex_number+1; i!=0;) {
		for (temp = list[p[i]].first_node; temp; temp = temp->next) {
			if(temp->vertex==i){
			ADDPATHQ(temp);
			break;
			}
		}
		i = p[i];
	}
	small = (path.first->capacity)-(path.first->flow);
	printf("\n");


	for (temp = path.first; temp->next != NULL; temp = temp->next) {
		if (small > (temp->capacity)-(temp->flow)) {
			small = temp->capacity;
		}

	}
	
	for (temp = path.first; temp; temp = temp->next) {
		temp->flow = temp->flow + small;
		temp->pair->flow = (-1)*(temp->flow);
	}

	DEPATHQ();
}
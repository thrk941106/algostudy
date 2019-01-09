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
root TopologList;
Queue queue;
int *color;
int *d;

//함수선언
void initList(node* temp, int start);
void DFS(int* p, int vertex);
void DFS_visit(int *p, int u_number);
void Topological_Sort(int u_number);
void BFS(int vertex_number, int* p);
void DEQUEUE();
void ENQUEUE(int data);
int main(void) {
	//파일 변수
	FILE *f;
	// vertex, edge 갯수 저장 변수
	int vertex_number, edge_number;
	// 그래프정보 저장 변수
	int start, end;
	// DFS Tree 배열
	int *p;
	// list 읽기용 temp 변수
	node* temp;
	// 기타 변수
	int i;


	// 파일열기

	fopen_s(&f, "input.txt", "r");

	//input에서 vertex,edge 갯수 읽어오기
	fscanf_s(f, "%d %d", &vertex_number, &edge_number);

	//필요 List, Array 생성 및 동적할당
	list = (root*)calloc(vertex_number + 1, sizeof(root));
	queue.first = NULL;
	queue.rear = NULL;
	TopologList.first_node = NULL;
	TopologList.last_node = NULL;
	p = (int*)calloc(vertex_number + 1, sizeof(int));
	d = (int*)calloc(vertex_number + 1, sizeof(int));

	color = (int*)calloc(vertex_number + 1, sizeof(int));

	// input 에서 값 읽어서 그래프를 AdjList 만들기
	for (i = 0; i < edge_number; i++) {
		temp = (node*)calloc(1, sizeof(node));
		fscanf_s(f, "%d %d", &start, &end);
		temp->vertex = end;
		initList(temp, start);
	}
/*	
	// Adjlist 출력하기
	for (i = 1; i <= vertex_number; i++) {
		printf("%d ", i);
		if (list[i].first_node == NULL) {
			printf("\n");
			continue;
		}
		for (temp = list[i].first_node; temp; temp = temp->next) {
			printf("(%d) ", temp->vertex);
		}
		printf("\n");
	}


	//DFS Tree 생성, 및 Topoligical sort 한 list 만들기
	DFS(p, vertex_number);

	//DFS Tree 출력
	for (i = 1; i <= vertex_number; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");
	/*
	//Topological list 출력
	for (temp = TopologList.first_node; temp; temp = temp->next) {
		printf("%d ", temp->vertex);
	}
	printf("\n");
	*/
	BFS(vertex_number, p);
	printf("BFS : ");
	for (i = 1; i <= vertex_number; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");

	free(list);
	fclose(f);
	system("pause");
}


// 리스트생성함수
void initList(node* temp, int start) {
	if (list[start].first_node == NULL)
		list[start].first_node = temp;
	else
		list[start].last_node->next = temp;
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

void BFS(int vertex_number, int* p) {
	node *u;
	node *v;
	for (int i = 1; i <= vertex_number; i++) {
		color[i] = WHITE;
		d[i] = INFINITY;
		p[i] = NIL;
	}
	color[1] = GRAY;
	d[1] = 0;
	ENQUEUE(1);
	while (queue.first != NULL) {
		u = queue.first;
		for (v = list[u->vertex].first_node; v; v = v->next) {
			if (color[v->vertex] == WHITE) {
				color[v->vertex] = GRAY;
				d[v->vertex] = d[u->vertex] + 1;
				p[v->vertex] = u->vertex;
				ENQUEUE(v->vertex);
			}
		}
		color[u->vertex] = BLACK;
		DEQUEUE();

	}
}

// DFS 함수
void DFS(int* p, int vertex) {
	int i;
	for (i = 1; i <= vertex; i++) {
		if (color[i] == WHITE) {
			DFS_visit(p, i);
		}
	}
}

//DFS_VISIT + Topological sort 함수
void DFS_visit(int *p, int u_number) {
	node *temp;
	color[u_number] = GRAY;
	for (temp = list[u_number].first_node; temp; temp = temp->next) {
		if (color[temp->vertex] == WHITE) {
			p[temp->vertex] = u_number;
			DFS_visit(p, temp->vertex);
		}
	}
	color[u_number] = BLACK; // 더이상 갈 곳이 없어서 색이 BLACK으로 바뀌면 바로 Topological_list 함수 호출
	Topological_Sort(u_number);
}

//Topological list 함수
void Topological_Sort(int u_number) {
	node *temp;
	temp = (node*)calloc(1, sizeof(node));
	temp->vertex = u_number;
	if (TopologList.last_node == NULL) {
		TopologList.last_node = temp;
		TopologList.first_node = temp;
	}
	else
	{
		temp->next = TopologList.first_node;
		TopologList.first_node = temp;
	}
}
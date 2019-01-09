#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INFINITY 99999
#define NIL -1


//����ü ����
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

//��������
root *list;
root TopologList;
Queue queue;
int *color;
int *d;

//�Լ�����
void initList(node* temp, int start);
void DFS(int* p, int vertex);
void DFS_visit(int *p, int u_number);
void Topological_Sort(int u_number);
void BFS(int vertex_number, int* p);
void DEQUEUE();
void ENQUEUE(int data);
int main(void) {
	//���� ����
	FILE *f;
	// vertex, edge ���� ���� ����
	int vertex_number, edge_number;
	// �׷������� ���� ����
	int start, end;
	// DFS Tree �迭
	int *p;
	// list �б�� temp ����
	node* temp;
	// ��Ÿ ����
	int i;


	// ���Ͽ���

	fopen_s(&f, "input.txt", "r");

	//input���� vertex,edge ���� �о����
	fscanf_s(f, "%d %d", &vertex_number, &edge_number);

	//�ʿ� List, Array ���� �� �����Ҵ�
	list = (root*)calloc(vertex_number + 1, sizeof(root));
	queue.first = NULL;
	queue.rear = NULL;
	TopologList.first_node = NULL;
	TopologList.last_node = NULL;
	p = (int*)calloc(vertex_number + 1, sizeof(int));
	d = (int*)calloc(vertex_number + 1, sizeof(int));

	color = (int*)calloc(vertex_number + 1, sizeof(int));

	// input ���� �� �о �׷����� AdjList �����
	for (i = 0; i < edge_number; i++) {
		temp = (node*)calloc(1, sizeof(node));
		fscanf_s(f, "%d %d", &start, &end);
		temp->vertex = end;
		initList(temp, start);
	}
/*	
	// Adjlist ����ϱ�
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


	//DFS Tree ����, �� Topoligical sort �� list �����
	DFS(p, vertex_number);

	//DFS Tree ���
	for (i = 1; i <= vertex_number; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");
	/*
	//Topological list ���
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


// ����Ʈ�����Լ�
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

// DFS �Լ�
void DFS(int* p, int vertex) {
	int i;
	for (i = 1; i <= vertex; i++) {
		if (color[i] == WHITE) {
			DFS_visit(p, i);
		}
	}
}

//DFS_VISIT + Topological sort �Լ�
void DFS_visit(int *p, int u_number) {
	node *temp;
	color[u_number] = GRAY;
	for (temp = list[u_number].first_node; temp; temp = temp->next) {
		if (color[temp->vertex] == WHITE) {
			p[temp->vertex] = u_number;
			DFS_visit(p, temp->vertex);
		}
	}
	color[u_number] = BLACK; // ���̻� �� ���� ��� ���� BLACK���� �ٲ�� �ٷ� Topological_list �Լ� ȣ��
	Topological_Sort(u_number);
}

//Topological list �Լ�
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
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define INFINITY 99999
#define NIL -1
#define FALSE 0
#define	TRUE 1

//구조체 정의
typedef struct node {
	int vertex;
	int weight;
	//int flow;
	struct node* next;
	//struct node* for_path;
}node;

typedef struct root {
	node* first_node;
	node* last_node;
}root;

typedef struct {
	int v;
	int w;
} tHeap;

int heapsize = 0;


//함수선언
void initList(root* list, node* temp, int start, int capacity);
void siftdown(tHeap *PQ, int i);
void insert_heap(tHeap *PQ, int v, int w);
int EXTRACT_MIN(tHeap *PQ);
void MST_Dijkstra(root* list, tHeap *PQ, int vertex_number, int *d, int *p, int* flag);
int W(root* list, int u, int v);

int main(void) {
	//파일 변수
	FILE *lf;
	// vertex, edge 갯수 저장 변수
	int vertex_number, edge_number;
	// 그래프정보 저장 변수
	int start, end, weight;
	// DFS Tree 배열
	int *p;
	int *d;
	int *flag;
	// list 읽기용 temp 변수
	node* temp;
	node* temp2;
	// 기타 변수
	int i;
	int ans = 0;
	//load input
	root *list;
	tHeap *PQ;

	//input에서 vertex,edge 갯수 읽어오기
	fopen_s(&lf, "input1.txt", "r");
	fscanf(lf, "%d %d", &vertex_number, &edge_number);

	//필요 List, Array 생성 및 동적할당
	list = (root*)calloc(vertex_number + 1, sizeof(root));
	p = (int*)calloc(vertex_number + 1, sizeof(int));
	d = (int*)calloc(vertex_number + 1, sizeof(int));
	flag = (int*)calloc(vertex_number + 1, sizeof(int));
	PQ = (tHeap *)calloc(edge_number + 1, sizeof(tHeap));
	// input 에서 값 읽어서 그래프를 AdjList 만들기

	for (i = 0; i < edge_number; i++) {
		temp = (node*)calloc(1, sizeof(node));
		fscanf_s(lf, "%d %d %d", &start, &end, &weight);
		temp->vertex = end;
		temp->weight = weight;
		initList(list, temp, start, weight);
	}

	for (i = 1; i <= vertex_number; i++) {
		printf("%d ", i);
		if (list[i].first_node == NULL) {
			printf("\n");
			continue;
		}
		for (temp = list[i].first_node; temp; temp = temp->next) {
			printf("(%d, %d) ", temp->vertex, temp->weight);
		}
		printf("\n");
	}

	MST_Dijkstra(list, PQ, vertex_number, d, p, flag);

	printf("parent : ");
	for (i = 1; i <= vertex_number; i++) {
		printf("%d ", p[i]);
	}
	printf("\nparent : ");

	for (i = 1; i <= vertex_number; i++) {
		printf("%d ", d[i]);
	}
	free(list);
	system("pause");
}


// 리스트생성함수
void initList(root* list, node* temp, int start, int weight) {
	if (list[start].first_node == NULL)
		list[start].first_node = temp;
	else {
		list[start].last_node->next = temp;
	}
	list[start].last_node = temp;
}


void MST_Dijkstra(root* list, tHeap *PQ, int vertex_number, int *d, int *p, int* flag)
{

	node* temp;
	int i;
	int u;
	for (i = 1; i <= vertex_number; i++) {
		d[i] = INFINITY;
	}
	d[1] = 0;
	p[1] = NIL;

	insert_heap(PQ, 1, 0);
	while (heapsize != 0) {
		u = EXTRACT_MIN(PQ);
		if (flag[u] == 0) {
			for (temp = list[u].first_node; temp; temp = temp->next) {
				if (flag[temp->vertex] == 0 && temp->weight + d[u] < d[temp->vertex]) {
					p[temp->vertex] = u;
					d[temp->vertex] = temp->weight + d[u];
					insert_heap(PQ, temp->vertex, d[temp->vertex]);
				}
			}
		}
		flag[u] = 1;
	}
}

void siftdown(tHeap *PQ, int i) {
	int siftkey_v = PQ[i].v, siftkey_w = PQ[i].w, parent = i, found = 0;
	int smaller_child;

	while (2 * parent <= heapsize && found == 0) {
		if (2 * parent < heapsize && PQ[2 * parent].w >= PQ[2 * parent + 1].w)
			smaller_child = 2 * parent + 1;
		else
			smaller_child = 2 * parent;
		if (siftkey_w > PQ[smaller_child].w) {
			PQ[parent] = PQ[smaller_child];
			parent = smaller_child;
		}
		else
			found = 1;
	}
	PQ[parent].v = siftkey_v;
	PQ[parent].w = siftkey_w;
}


int EXTRACT_MIN(tHeap *PQ) {
	tHeap root = PQ[1];
	int result = root.v;

	PQ[1] = PQ[heapsize];
	heapsize--;
	siftdown(PQ, 1);
	return result;
}


void insert_heap(tHeap *PQ, int v, int w)
{
	int parent = ++heapsize / 2;
	int index = heapsize;
	while (parent > 0 && w < PQ[parent].w) {
		PQ[index] = PQ[parent];
		index = parent;
		parent /= 2;
	}

	PQ[index].v = v;
	PQ[index].w = w;
}
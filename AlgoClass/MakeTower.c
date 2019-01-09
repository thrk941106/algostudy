#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INFINITY 99999
#define NIL 0
int *d;
int *p;
//����ü ����
typedef struct node {
	int hight;
	int name;
	struct node* next;
}node;

typedef struct root {
	node* first_node;
	node* last_node;
}root;

typedef struct block {
	int width;
	int height;
	int weight;
}block;


//��������
root *list;
root TopologList;
block *blocks;
int *color;
int *d;
int *p;
int *top;
int highest;

//�Լ�����
void initList(node* temp, int start);
void DFS(int* p, int vertex);
void DFS_visit(int *p, int u_number);
void Topological_Sort(int u_number);
void INITIALIZE_SINGLE_SOURCE(int s);
void BELLMAN_FORD(int block_number);
void RELAX(int u, int v);
int Weight_between(int u, int v);
int main(void) {
	// DFS Tree �迭
	//���� ����
	FILE *f;
	
	// ���� ����
	int  block_number;
	
	// ���� ���� ���� ����
	int width, weight, height;
	
	// list �б�� temp ����
	node* temp;

	// ��Ÿ ����
	int i, j, tower_block=0;
	
	// ���Ͽ���
	fopen_s(&f, "input.txt", "r");

	//input���� block ���� �о����
	fscanf_s(f, "%d", &block_number);

	//�ʿ� List, Array ���� �� �����Ҵ�
	list = (root*)calloc(block_number + 3, sizeof(root));
	blocks = (block*)calloc(block_number + 3, sizeof(block));
	
	
	TopologList.first_node = NULL;
	TopologList.last_node = NULL;
	p = (int*)calloc(block_number + 3, sizeof(int));
	color = (int*)calloc(block_number + 3, sizeof(int));
	d = (int*)calloc(block_number + 3, sizeof(int));

	//������� ���� �� �ʱ�ȭ
	for (i = 0; i <= block_number+1; i++) {
		if (i == 0) {
			blocks[i].height = NIL;
			blocks[i].weight = INFINITY;
			blocks[i].width = INFINITY;
		}
		else if (i == block_number + 1) {
			blocks[i].height = NIL;
			blocks[i].weight = NIL;
			blocks[i].width = NIL;
		}
		else {
			fscanf_s(f, "%d %d %d", &width, &height, &weight);
			blocks[i].height = height;
			blocks[i].weight = weight;
			blocks[i].width = width;
		}
		p[i] = -1;
		d[i] = INFINITY;
	}


	for (i = 0; i <= block_number+1; i++) {
		for (j = 0; j <= block_number+1; j++) {
			if (i == j) {
				continue;
			}
			if (blocks[i].width > blocks[j].width && blocks[i].weight > blocks[j].weight) {
				if (i == 0 && j == 6) {
					continue;
				}
				temp = (node*)calloc(1, sizeof(node));
				temp->hight = blocks[i].height;
				temp->name = j;
				initList(temp, i);
			}
		}
	}

	for (i = 0; i <= block_number+1; i++) {
		printf("%d ", i);
		if (list[i].first_node == NULL) {
			printf("\n");
			continue;
		}
		for (temp = list[i].first_node; temp; temp = temp->next) {
			printf("(%d %d) ", temp->name,temp->hight);
		}
		printf("\n");
	}
	DFS(p, block_number+1);

	for (i = 0; i <= block_number+1; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");

	for (temp = TopologList.first_node; temp; temp = temp->next) {
		printf("%d ", temp->name);
	}
	printf("\n\n\n");
	

	BELLMAN_FORD(block_number+1);
	i = block_number+1;
	while (p[i] != 0) {
		tower_block++;
		i = p[i];
	}
	printf("%d\n", tower_block);
	i = block_number + 1;
	while (p[i] != 0) {
		printf("%d\n", p[i]);
		i = p[i];
	}
	printf("height : %d\n", d[block_number+1]);
	free(temp);
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

//DFS �Լ�
void DFS(int* p, int vertex) {
	int i;
	for (i = 0; i <= vertex; i++) {
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
		if (color[temp->name] == WHITE) {
			p[temp->name] = u_number;
			DFS_visit(p, temp->name);
		}
	}
	color[u_number] = BLACK; // ���̻� �� ���� ��� ���� BLACK���� �ٲ�� �ٷ� Topological_list �Լ� ȣ��
	Topological_Sort(u_number);
}

//Topological list �Լ�
void Topological_Sort(int u_number) {
	node *temp;
	temp = (node*)calloc(1, sizeof(node));
	temp->name = u_number;
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


void BELLMAN_FORD(int block_number) {
	int max=0;
	node *temp;
	node *temp2;
	INITIALIZE_SINGLE_SOURCE(block_number);

	for (temp = TopologList.first_node; temp;  temp = temp->next) {
		for (temp2 = list[temp->name].first_node; temp2;temp2= temp2->next) {
			RELAX(temp->name, temp2->name);
		}
	}
}

void RELAX(int u, int v) {
	int W= Weight_between(u, v);
	if (d[v] <= d[u] + W) {
		d[v] = d[u] + W;
		p[v] = u;
	}
}

int Weight_between(int u,int v) {
	int i;
	node *temp;
	for (temp = list[u].first_node; temp; temp = temp->next) {
		if (temp->name == v) {
			return temp->hight;
		}
	}
}

void INITIALIZE_SINGLE_SOURCE(int block_number) {
	int i;

	for (i = 0; i <= block_number + 1; i++) {
		d[i] = 0;
		p[i] = -1;
	}
	d[0] = 0;
}
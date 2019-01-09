#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node {
	int vertex;
	int weight;
	struct node* next;
}node;

typedef struct root {
	node* first_node;
	node* last_node;
}root;

void initList(root* list, FILE* f, int vertex, int edge) {
	int i;
	node* temp;
	int start, end, weight;
	for (i = 0; i < edge; i++) {
		temp = (node*)calloc(1, sizeof(node));
		fscanf_s(f, "%d %d %d", &start, &end, &weight);
		temp->vertex = end;
		temp->weight = weight;

		if (list[start].first_node == NULL)
			list[start].first_node = temp;
		else
			list[start].last_node->next = temp;

		list[start].last_node = temp;
	}
}

int main(void) {
	root *list;
	int vertex_number;
	int edge_number;
	FILE *f;
	int i;
	node* temp;

	fopen_s(&f, "input.txt", "r");

	fscanf_s(f, "%d %d", &vertex_number, &edge_number);
	list = (root*)calloc(vertex_number + 1, sizeof(root));
	initList(list, f, vertex_number, edge_number);

	for (i = 1; i <= vertex_number; i++) {

		printf("%d ", i);
		if (list[i].first_node == NULL) {
			printf("\nNothing\n\n");
			continue;
		}	
		printf("\n");
		for (temp = list[i].first_node; temp; temp = temp->next) {
			printf("vertex : %d weight : %d\n", temp->vertex, temp->weight);
		}
		printf("\n");
	}
	system("pause");
}
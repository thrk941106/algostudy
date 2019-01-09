#define _CRT_SECURE_NO_WARNINGS
#define FALSE 0
#define	TRUE 1
#include<stdio.h>
#include<stdlib.h>
int heapsize;
int s[999];
int H[999];
int H_backup[999];

void insert(int* H, int n) {
	int siftkey = n;
	int child = ++heapsize;
	int smallerparent;
	int found = FALSE;
	H[heapsize] = n;
	while (child > 1 && found == FALSE) {
		if (child / 2 == 1) {
			smallerparent = 1;
		}
		else if ((child / 2) %2 ==0) {
			if (H[child / 2] > H[child / 2 + 1]) {
				smallerparent = child / 2 + 1;
			}
			else {
				smallerparent = child / 2;
			}
		} else {
			if (H[child / 2] > H[child / 2 - 1]) {
				smallerparent = child / 2 - 1;
			}
			else {
				smallerparent = child / 2;
			}
		}
		if (siftkey < H[smallerparent]) {
			H[child] = H[smallerparent];
			child = smallerparent;
		}
		else {
			found = TRUE;
		}
	}
	H[child] = siftkey;

}
void siftdown(int* H, int i) {
	int siftkey;
	int parent=i;
	int smallerchild;
	int found = FALSE;
	siftkey = H[i];
	while (parent * 2 <= heapsize && found == FALSE) {
		if (2 * parent < heapsize && H[2 * parent] > H[2 * parent + 1]) {
			smallerchild = 2 * parent + 1;
		}
		else {
			smallerchild = 2 * parent;
		}
		if (siftkey > H[smallerchild]) {
			H[parent] = H[smallerchild];
			parent = smallerchild;
		}
		else {
			found = TRUE;
		}
	}
	H[parent] = siftkey;
}
void makeheap(int n, int* H) {
	int i;
	heapsize = n;
	for (i = n / 2; i >= 1; i--) {
		siftdown(H, i);
	}
}
int root(int* H) {
	int keyout = H[1];
	H[1] = H[heapsize--];
	siftdown(H, 1);
	return keyout;
}

void removekeys(int n, int* H, int* s) {
	int i;
	for (i = 1; i <= n; i++) {
		s[i] = root(H);
	}
}

void heapsort(int n, int* H) {
	int i;
	int heapsize_b=heapsize;
	makeheap(n, H);
	for (i = 1; i <= heapsize; i++) {
		H_backup[i] = H[i];
	}
	removekeys(n, H, s);
	heapsize = heapsize_b;
	for (i = 1; i <= heapsize; i++) {
		H[i] = H_backup[i];
	}
	
}
void Print(int* arr) {
	int i;
	FILE *out;
	out = fopen("output.txt", "w");
	for (i = 1; i <= heapsize; i++) {
		printf("%d ", arr[i]);
		fprintf(out,"%d ", arr[i]);
	}
	fprintf(out,"\n");
	printf("\n ");
}



int main(void) {
	char mode;
	int n;
	int num;
	int i;
	FILE *in;
	in = fopen("input.txt", "r");
	fscanf(in, "%d", &heapsize);
	for (i = 1; i <= heapsize; i++) {
		fscanf(in, "%d", &H[i]);
	}
	makeheap(heapsize, H);
	printf("makeheap : ");
	Print(H);
	heapsort(heapsize, H);
	printf("heapsort : ");
	Print(s);
	Print(H);
	printf("Insert : i\nDelete : d\nfinish : f");
	scanf(" %c", &mode);
	printf("\n");
	while (mode != 'f') {
		if (mode == 'i') {
			printf("Insert number : ");
			scanf("%d", &num);
			insert(H, num);
			Print(H);
		}
		else if (mode == 'd') {
			n = root(H);
			printf("%d\n", n);
			Print(H);
		}
		else {
			printf("error");
		}
		scanf(" %c", &mode);
	}
	system("pause");
}
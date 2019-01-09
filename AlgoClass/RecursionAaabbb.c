#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
char arr[9999];

void quicksort(int low, int high);
void partition(int low, int high, int *index_pivot);
void rand_partition(int low, int high, int *index_pivot);

void quicksort(int low, int high) {
	int index_pivot;
	if (high > low) {
		rand_partition(low, high, &index_pivot);
		quicksort(low, index_pivot - 1);
		quicksort(index_pivot + 1, high);
	}

}

void rand_partition(int low, int high, int *index_pivot) {
	srand(time(NULL));
	char temp;
	int i = rand() % (high - low + 1) + low;
	temp = arr[low];
	arr[low] = arr[i];
	arr[i] = temp;
	partition(low, high, index_pivot);
}
void partition(int low, int high, int *index_pivot) {
	char temp;
	int i, j;
	char item_pivot = arr[low];
	j = low;
	for (i = low + 1; i <= high; i++) {
		if (arr[i] < item_pivot) {
			j++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	*index_pivot = j;
	temp = arr[low];
	arr[low] = arr[j];
	arr[j] = temp;
}

void perm(int k, int n) {
	int m;
	char temp;
	if (k >= n) {
		printf("%s\n", arr);
	}
	else {
		quicksort(k, n);
		perm(k + 1, n);
		quicksort(k + 1, n);
		m = k + 1;
		while (m <=n) {
			if (arr[m] > arr[k]) {
				temp = arr[m];
				arr[m] = arr[k];
				arr[k] = temp;
				perm(k + 1, n);
				quicksort(k + 1, n);
			}
			m++;
		}
	}

}

int main(void) {
	int number_arr;
	printf("문자열을 입력하십시오 : ");
	gets(arr);
	number_arr = strlen(arr);
	perm(0, number_arr - 1);
	system("pause");
}
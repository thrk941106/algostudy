#include <stdio.h>
#include <stdlib.h>
int arr[8] = { 15,22,13,27,12,10,20,25 };

void quicksort(int low, int high);
void partition(int low, int high, int *index_pivot);

void quicksort(int low, int high) {
	int index_pivot;
	if (high > low) {
		partition(low, high, &index_pivot);
		quicksort(low, index_pivot - 1);
		quicksort(index_pivot+1, high);
	}

}
void partition(int low, int high, int *index_pivot) {
	int temp;
	int i, j;
	int item_pivot = arr[low];
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
	temp= arr[low];
	arr[low] = arr[j];
	arr[j] = temp;
}

int main() {
	int i;
	quicksort(0, 7);
	for (i = 0; i < 8; i++) {
		printf("%d ", arr[i]);
	}
	system("pause");
}
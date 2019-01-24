#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long arr0[91];
	long long arr1[91];
	int n;
	arr0[1] = 0;
	arr1[1] = 1;
	arr0[2] = 1;
	arr1[2] = 0;
	for (int i = 3; i <= 90; i++) {
		arr0[i] = arr0[i - 1] +arr1[i-1];
		arr1[i] = arr0[i - 1];
	}
	cin >> n;
	cout << arr0[n] + arr1[n];


}

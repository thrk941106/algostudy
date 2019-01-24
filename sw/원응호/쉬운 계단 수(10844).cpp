#include<iostream>
#include<vector>
using namespace std;
long long arr[101][11];
int n, sum = 0;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= 9; i++)
		arr[1][i] = 1;
	arr[1][10] = 0;
	arr[0][1] = 1;
	for (int i = 2; i <= n; i++) {
		arr[i][1] = (arr[i - 1][2] + arr[i - 2][1]) % 1000000000;
		for (int j = 2; j <= 9; j++) {
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;
		}arr[i][10] = 0;
	}
	for (int i = 1; i <= 9; i++)
		sum = (sum + arr[n][i]) % 1000000000;
	cout << sum;

}

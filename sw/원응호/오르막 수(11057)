#include<iostream>
#include<vector>
using namespace std;
int arr[1001][11];
int n, sum = 0;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i <= 9; i++)
		arr[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		arr[i][0] = 1;
		for (int j = 1; j <= 9; j++) {
			arr[i][j] = (arr[i][j - 1] + arr[i - 1][j])%10007;
		}
	}
	for (int i = 0; i <= 9; i++)
		sum = (sum + arr[n][i]) % 10007;
	cout << sum;

}

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int n;
int arr[2][100001];
int ansu[100001];
int ansd[100001];
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		memset(arr, 0, sizeof(arr));
		memset(ansu, 0, sizeof(ansu));
		memset(ansd, 0, sizeof(ansd));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int u;
			cin >> u;
			arr[0][i] = u;
		}
		for (int i = 1; i <= n; i++) {
			int d;
			cin >> d;
			arr[1][i] = d;
		}
		ansu[0] = 0;
		ansd[0] = 0;
		for (int i = 1; i <= n; i++) {
			int a, b, c, d;
			a= arr[0][i] + ansd[i - 1];
			b = std::max(ansd[i - 2], ansu[i - 2]) + arr[0][i];
			ansu[i] = std::max(a, b);


			c = arr[1][i] + ansu[i - 1];
			d = std::max(ansd[i - 2], ansu[i - 2]) + arr[1][i];
			ansd[i] = std::max(c, d);
		}
		if (ansu[n] < ansd[n])
			cout << ansd[n] << '\n';
		else
			cout << ansu[n] << '\n';
	}

}

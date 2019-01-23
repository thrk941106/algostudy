#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long ans[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;

	while (T--) {
		cin >> n;
		ans[1] = 1;
		ans[2] = 2;
		ans[3] = 4;
		for (int i = 4; i <= n; i++) {
			ans[i] = ans[i - 3] + ans[i - 2] + ans[i - 1];
			ans[i] %= 1000000009;
		}
		cout << ans[n]<<'\n';
	}
}

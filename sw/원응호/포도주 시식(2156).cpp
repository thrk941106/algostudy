#include<iostream>
#include<algorithm>
using namespace std;
int arr[10001];
int ans0[10001],ans1[10001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	ans0[1] = 0; ans1[1] = arr[1];
	ans0[2] = arr[1]; ans1[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++) {
		ans0[i] = std::max(ans0[i - 1],ans1[i - 1]);
		ans1[i] = std::max(ans1[i - 2]+arr[i],ans0[i - 2]+arr[i-1]+arr[i]);
	}
	if (ans0[n] < ans1[n])
		cout << ans1[n];
	else
		cout << ans0[n];
}

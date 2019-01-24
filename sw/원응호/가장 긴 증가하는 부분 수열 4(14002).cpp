#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int arr[1001];
int ans[1001];
set<int> v[1001];

int main()
{
	ios::sync_with_stdio(false);
	int answer = 0;
	cin.tie(0); cout.tie(0);
	int n, cnt = 0, max = 0, temp;
	int check;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ans[i] = 1;
		v[i].insert(arr[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && ans[i] <= ans[j]) {
				ans[i] = ans[j] + 1;
				v[i]=v[j];
				v[i].insert(arr[i]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (answer < ans[i]) {
			answer = ans[i];
			check = i;
		}
	}
    
	cout << answer << '\n';
	for (auto i : v[check])
		cout << i<<' ';
}

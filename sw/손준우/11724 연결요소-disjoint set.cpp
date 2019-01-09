#include<iostream>
#include<vector>
#include<algorithm>
#define NIL -1
using namespace std;


int find(int *p, int i) {
	int r, s;
	for (r = i; p[r] >= 0; r = p[r]);

	while (i != r) {
		s = p[i];
		p[i] = r;
		i = s;
	}
	return r;
}

void weighted_union(int* p, int i, int j) {
	int temp = p[i] + p[j];
	if (p[i] > p[j]) {
		p[i] = j;
		p[j] = temp;
	}
	else {
		p[j] = i;
		p[i] = temp;
	}
}

int main(){
    int n, m;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int p[n+1];
    int cnt=0;
    vector<int> graph[n+1];
    fill(p, p+n+1, NIL);
    
    while(m--){
        int s, d;
        int p1, q1;
        cin >> s >> d;
        if ((p1 = find(p, s) ) != (q1= find(p, d))) {
			weighted_union(p ,p1, q1);
		}
    }
    
    for(int i = 1 ; i<=n ; i++) {
        if(p[i] < 0){
            cnt++;
        }
    }
    cout << cnt;
}
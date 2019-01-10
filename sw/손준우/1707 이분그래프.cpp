#include<iostream>
#include<vector>
#include<algorithm>
#define WHITE 0
using namespace std;
vector<int> graph[20001];
int color[20001];

bool dfs(int start, int c){
    color[start] = c;
    for(int i = 0 ; i < graph[start].size() ; i++) {
        int next = graph[start][i];
        if(color[next]==WHITE){
            if(!dfs(next,3-c)){
                return false;
            }
        } else if(color[next] == c) {
                return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_cnt, v, e, s, d;
    cin >> test_cnt;

    while(test_cnt--) {
        cin >> v >> e;
        for (int i=1; i<=v; i++) {
            graph[i].clear();
            color[i] = WHITE;
        }
        while(e--){
			cin >> s >> d;
            graph[s].push_back(d);
            graph[d].push_back(s);
        }
        bool ok = true;
        for(int i = 1 ; i <= v ; i++){
            if(color[i] == WHITE){
                if(!dfs(i, 1)){
                    ok = false;
                    cout << "NO"<<'\n';
                    break;
                } 
            }
        }
        if (ok == true) cout << "YES" << '\n';
    }
}
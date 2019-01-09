#include<iostream>
#include<vector>
#include<algorithm>
#define WHITE 0
#define BLACK 1
using namespace std;

void dfs(vector<int> *v, int start, int *color){
    color[start] = BLACK;
    for(int i = 0 ; i < v[start].size() ; i++){
        int next = v[start][i];
        if( color[next]== WHITE) {
            dfs(v,next,color);
        }
    }
}

int main(){
    int n, m;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int color[n+1];
    int cnt=0;
    vector<int> graph[n+1];
    fill(color, color+n+1, WHITE);
    
    while(m--){
        int s, d;
        cin >> s >> d;
        graph[s].push_back(d);
        graph[d].push_back(s);        
    }
    
    for(int i = 1 ; i<=n ; i++) {
        if(color[i] == WHITE){
            dfs(graph,i,color);
            cnt++;
        }
    }
    cout << cnt;
}
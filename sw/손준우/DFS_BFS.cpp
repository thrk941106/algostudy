#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;
queue<int> q;

void BFS(vector<int> *v, int x, int *color){
	q.push(x);
    color[x] = BLACK;
    while(!q.empty()){
        int next =q.front();
        q.pop();
        cout << next << ' ';
        for(int i=0 ; i<v[next].size() ; i++) {
            int y = v[next][i];
            if(color[y] != BLACK) {
                color[y] = BLACK;
                q.push(y);
            }
        }
    }
}


void DFS(vector<int> *v, int x, int *color){
    color[x] = GRAY;
    cout << x << ' ';
    for(int i=0 ; i<v[x].size() ; i++) {
        int next =v[x][i];
        if(color[next] == WHITE) {
            DFS(v, next, color);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int n, m, starting_point;
    cin >> n >> m >> starting_point;
    vector<int> v[n+1];
    int color[n+1];
    fill(color, color+n+1, WHITE);
    
    while(m--){
        int start, destination;
        cin >> start >> destination;
        v[start].push_back(destination);
        v[destination].push_back(start);
    }
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    
    DFS(v, starting_point, color);
    cout << '\n';
    BFS(v, starting_point, color);
    
}
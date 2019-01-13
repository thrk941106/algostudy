#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define WHITE 0
using namespace std;
int map[101][101];
int color[101][101];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n,m;

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    color[x][y] = 1;
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int d=0 ; d<4 ; d++){
            int nx = x+dx[d], ny = y+dy[d];
            if(0<nx && 0<ny && nx<=n && ny <=m){
                if(map[nx][ny]==1 && color[nx][ny]==WHITE){
                    q.push({nx,ny});
                    color[nx][ny]= color[x][y]+1;
                    if(nx==n && ny==m){
                        cout <<  color[nx][ny];
                        return;
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            char c;
            cin >> c;
            map[i][j] = c-'0';
            color[i][j] = WHITE;
        }
    }
    bfs(1,1);

    
}
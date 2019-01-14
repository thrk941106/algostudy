#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
int a[1001][1001];
vector<pair<int,int> > v;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
queue<pair<int,int>> q;
int cnt;
int MAX=1;

int bfs() {
	int x, y;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int k=0 ; k<4 ; k++){
            int nx = x+dx[k], ny=y+dy[k];
            if(0<nx && 0<ny && nx<=n && ny <= m){
                if(a[nx][ny]==0){
                    q.push({nx,ny});
                    a[nx][ny] = a[x][y]+1;
                    if(MAX < a[nx][ny]){
                        MAX = a[nx][ny];   
                    }
                }
            }
        }   
    }
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(a[i][j]==0){
        		return -1;
        	}
        }
    }
    return MAX-1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            cin >> a[i][j];
            if(a[i][j]==1){
                q.push({i,j});
            }
        }
    }


    cout <<  bfs();
    
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int dx[] = {1,-1,0,0,1,1,-1,-1};
int dy[] = {0,0,1,-1,1,-1,1,-1};
int map[51][51];
int d[51][51];
int w, h;
void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    d[x][y]=1;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int k = 0 ; k<8 ; k++){
            int nx = x +dx[k], ny = y+dy[k];
            if(0<nx && 0<ny && ny<=w && nx <=h){
                if(d[nx][ny]==0 && map[nx][ny] == 1){
                    q.push({nx,ny});
                    d[nx][ny] = 1;
                }
            }
        }   
    }
}
    


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt = 0;
    while(1){
        cin >> w >> h;
        if(w==0 && h==0){
            break;
        }
        for(int i = 1 ; i<=h ; i++) {
            for(int j = 1 ; j<=w ; j++){
                cin >> map[i][j];
                d[i][j] = 0;
            }  
        }
        for(int i=1 ; i<=h ; i++){
            for(int j=1 ; j<=w ; j++) {
                if(map[i][j]==1 && d[i][j]==0){
                    bfs(i,j);
                    cnt++;   
                }
            }
        }
        cout << cnt << '\n';
        cnt = 0;
    }   
}
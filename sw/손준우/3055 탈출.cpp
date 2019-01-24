#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<tuple>

using namespace std;
int R,C;
char a[51][51];
int d[51][51];
int w[51][51];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
queue<pair<int,int> > q;
queue<pair<int,int> > water;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;
    for(int i=1; i<=R ; i++){
        for(int j=1 ; j<=C ; j++){
            cin >> a[i][j];
            if(a[i][j]=='S'){
                q.push(make_pair(i,j));
            }else if(a[i][j]=='*'){
                water.push(make_pair(i,j));
            }
        }
    }
    while(!water.empty()){
        int x, y;
        tie(x,y) = water.front();
        water.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<=R && ny<=C && 0<nx && 0<ny){
                    if((a[nx][ny]=='.'|| a[nx][ny]=='S')
                                           && w[nx][ny]==0){
                        water.push(make_pair(nx,ny));
                        w[nx][ny] = w[x][y]+1;
                    }
            }      
        }
    }

    while(!q.empty()){
        int x, y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<=R && ny<=C && 0<nx && 0<ny){
                if(w[nx][ny]==0 || w[nx][ny]>d[x][y]+1){
                    if(a[nx][ny]!='X'&&d[nx][ny]==0) {
                        q.push(make_pair(nx,ny));
                        d[nx][ny] = d[x][y]+1;
                        
                        if(a[nx][ny]=='D'){
                            cout << d[x][y]+1;
                            return 0;
                        }

                    } 
                }
            }      
        }
    }
    cout << "KAKTUS";
    return 0;
    
}


#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<tuple>
using namespace std;
int N,M;
deque<pair<int,int> > q;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int a[101][101];
int d[101][101];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    memset(d,-1,sizeof(d));
    for(int i =1 ; i<=M ; i++){
        for(int j=1 ; j<=N ; j++){
            char c;
            cin >> c;
            a[i][j]=c-'0';
        }
    }
    q.push_back({1,1});
    d[1][1]=0;
	while(!q.empty()){
        int x,y;
        tie(x,y)=q.front();
        q.pop_front();
        for(int i=0; i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];    
            if(ny<=N && nx<=M && 0<nx && 0<ny){
                if(d[nx][ny]==-1){
                    if(a[nx][ny]==0){
                        q.push_front({nx,ny});
                        d[nx][ny] = d[x][y];
                    }
                    else if(a[nx][ny]==1){
                        q.push_back({nx,ny});
                        d[nx][ny] = d[x][y]+1;
                    }
                }
            }
        }
    }
    cout << d[M][N];
}
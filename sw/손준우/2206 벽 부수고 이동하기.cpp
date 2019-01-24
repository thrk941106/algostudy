#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>

using namespace std;
int a[1001][1001];
int d[1001][1001][2];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
queue<tuple<int, int, int> >q;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin >> N >> M;
    for(int i =1 ; i<=N ; i++){
        for(int j=1 ; j<=M ; j++){
            char c;
            cin >> c;
            a[i][j]=c-'0';
        }
    }
    q.push(make_tuple(1,1,0));
    d[1][1][0]=1;
    while(!q.empty()){
        int x, y, z;
        tie(x,y,z) = q.front();
        q.pop();
        
        for(int i=0 ; i<4 ; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<=N && ny <= M && 0<nx && 0<ny) {
                if(a[nx][ny] == 0 && d[nx][ny][z]==0){
                    d[nx][ny][z] = d[x][y][z] +1;
					q.push(make_tuple(nx,ny,z));
                }
                else if(z==0 && a[nx][ny]==1 && d[nx][ny][z+1]==0){
                    d[nx][ny][z+1] = d[x][y][z] +1;
					q.push(make_tuple(nx,ny,z+1));
                }
            }
        }
    }
    if(d[N][M][0]!=0 && d[N][M][1]!=0){
    	cout << min(d[N][M][0],d[N][M][1]);
    	return 0;
    }
    else if(d[N][M][0]!=0){
        cout << d[N][M][0];
        return 0;
    } else if(d[N][M][1]!=0){
        cout << d[N][M][1];
		return 0;
    } else {
        cout << -1;
        return 0;
    }
	
}
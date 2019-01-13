#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int map[26][26];
int d[26][26];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int arr[625];
int number_apt=0;
    int n;
void bfs(int x, int y, int cnt) {
    queue<pair<int,int>> q;
    q.push({x,y});
    d[x][y] = cnt;
    number_apt++;
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int k=0; k<4 ; k++){
            int nx = x+dx[k], ny=y+dy[k];
            if(0<nx && nx<=n && 0<ny && ny<=n){
                if(d[nx][ny]==0 && map[nx][ny] == 1){
                    q.push({nx,ny});
                    d[nx][ny] = cnt;
                    number_apt++;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1 ; i<=n ; i++) {
        for(int j = 1 ; j<=n ; j++){
            char c;
            cin >> c;
            map[i][j] = c - '0';
            d[i][j] = 0;
        }
    }
    int cnt = 0;
    for(int i = 1 ; i<=n ; i++) {
        for(int j = 1 ;j<=n;j++){
            if(d[i][j]==0 && map[i][j] == 1){
                bfs(i,j,++cnt);
                arr[cnt]=number_apt;
                number_apt=0;
            }
        }
    }
    sort(arr+1,arr+cnt+1);
    cout << cnt << '\n';
    for(int k = 1 ; k <=cnt ; k++){
        cout << arr[k] << '\n';
    }
}
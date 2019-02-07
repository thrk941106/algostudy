#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
int a[21][21];
int N,M;
int x,y;
int k;
int order;
int d[7];
int dy[] = {1,-1,0,0};
int dx[] = {0,0,-1,1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> x >> y >> k;
    for(int i =0; i<N ; i++){
        for(int j =0 ; j<M ; j++){
            cin >> a[i][j];
        }
    }
    
    while(k--){
        cin >> order;
        int nx = x+dx[order-1];
        int ny = y+dy[order-1];

        if(0<=nx && 0<=ny && nx<N && ny <M){
        	x = nx;
        	y = ny;
            int temp = d[1];
            if(order == 1){
                d[1] = d[3];
                d[3] = d[6];
                d[6] = d[4];
                d[4] = temp;
            }else if(order == 2){
                d[1] = d[4];
                d[4] = d[6];
                d[6] = d[3];
                d[3] = temp;
            }else if(order == 3){
                d[1] = d[2];
                d[2] = d[6];
                d[6] = d[5];
                d[5] = temp;

            }else if(order == 4){
                d[1] = d[5];
                d[5] = d[6];
                d[6] = d[2];
                d[2] = temp;
            }
            
            if(a[nx][ny] == 0){
                a[nx][ny] = d[6];
            } else {
                d[6] = a[nx][ny];
                a[nx][ny] = 0;
            }
            
            cout << d[1] << '\n';
            
        }
        
    }
    
    
}
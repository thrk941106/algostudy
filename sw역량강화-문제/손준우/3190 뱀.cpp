#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int N,K;
int L;
int a[101][101]={0,};
int ans = 1;
int currentC = 1;
deque<pair<int, int> > snake;
int x=1;
int y=1;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    while(K--){
        int r,c;
        cin >> r >> c;
        a[r][c] = -1;
    }
    a[x][y] =1;
    snake.push_back(make_pair(x,y));
    cin >> L;
    int X;
    char C;
    L++;
    while(L--){
    	if(L==0){
    		X=10000;
    	}else{
        	cin >> X >> C;

    	}
    	x=snake.back().first;
        y=snake.back().second;
        for(int i=ans ; i<=X ; i++){
            int nx = x+dx[currentC];
            int ny = y+dy[currentC];
            if(0<nx && nx<=N && 0<ny && ny<=N){
                if(a[nx][ny] == 1){
                	cout << ans;
                    return 0;
                }else{
                    ans++;
                    x = nx;
                    y = ny;
                    if(a[nx][ny] == 0){
                        a[snake.front().first][snake.front().second]=0;
                        snake.pop_front();
                    }
                    a[nx][ny]=1;
                    snake.push_back(make_pair(nx, ny));
                }
            }else{
            	cout << ans;
            	//cout << "@2";
                return 0;
            }
        }
        if(C=='D'){
            currentC=(currentC+1)%4;
        } else{
            currentC = (currentC+3)%4;
        }
    }
    cout << ans;
}
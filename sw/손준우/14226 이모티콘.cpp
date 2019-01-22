#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>

using namespace std;
int S;
int arr[1001][1001];

void bfs(){
    queue<pair<int,int>> q;
    q.push({1,0});
    arr[1][0]=0;
    while(!q.empty()){
        int x,c;
        tie(x,c) = q.front();
        q.pop();
        if(x==S){
            cout<<arr[x][c];
            return;
        }
        if(arr[x][x]==-1){
            arr[x][x] = arr[x][c] +1;
            q.push({x,x});
        }
        if(x+c<=1000 && arr[x+c][c]==-1){
            arr[x+c][c] = arr[x][c] +1;
            q.push({x+c,c});
        }
        if(x-1>=0 && arr[x-1][c]==-1){
            arr[x-1][c] = arr[x][c] +1;
            q.push({x-1,c});
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> S;
    memset(arr,-1,sizeof(arr));
    bfs();
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,k;
int color[100001];

void bfs(){
    int x;
    queue<int> q;
    q.push(n);
    
    
    while(!q.empty()){
        x=q.front();
        q.pop();
        if(x == k){
          		cout << color[x];
         		return;
		}
        for( int i=0 ; i<3 ; i++ ){
            int nx;
            switch(i){
                case 0 : 
                   nx = x+1;
				   break;
                case 1 :
                    nx = x-1;
					break;
                case 2 :
                    nx = x*2;
					break;
            }
            if(0<=nx  && nx <=100000 && color[nx]==0){           	
            	color[nx] = color[x] +1;
            	q.push(nx);
            }
        }  
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    bfs();
}
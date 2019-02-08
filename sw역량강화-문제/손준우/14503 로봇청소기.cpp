#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
int N,M,r,c,d;
int room[50][50];
int a[50][50];
int dr[] ={-1,0,1,0};
int dc[] ={0,1,0,-1};
int before=0;

void dfs(int start_r,int start_c, int d){
	if(a[start_r][start_c]==0){
		before = before+1;
    	a[start_r][start_c] = before;
	}

    
    int cd=d;
    for(int i = 1; i<=4 ; i++){
    		cd=d-1;
    		if(cd<0){
    			cd=4+cd;
    		}  		
            int nr = start_r+dr[cd];
            int nc = start_c+dc[cd];
            
            if(0<=nr && 0<=nc && nr<N && nc<M && a[nr][nc]==0  && room[nr][nc]==0){
                    dfs(nr,nc,cd);
                    return;
            }else{
            	d =cd;
            }
    }
    cd=(d+2)%4;
    int nr = start_r+dr[cd];
    int nc = start_c+dc[cd];
    if(0<=nr && 0<=nc && nr<N && nc<M && room[nr][nc]==0){
        dfs(nr,nc,d);
    }
}

int main(){
    scanf("%d %d",&N,&M);
    scanf("%d %d %d",&r,&c,&d);

    for(int i = 0 ; i<N ; i++){
        for(int j=0 ; j<M ; j++){
            scanf("%d",&room[i][j]);
        }
    }
    dfs(r,c,d);
    printf("%d",before);
}
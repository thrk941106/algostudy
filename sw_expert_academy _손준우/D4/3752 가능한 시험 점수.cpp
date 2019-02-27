#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int T,N;
int a[101];
int sum=0;
int ans=1;
bool d[10001];
void Set_Case(){
	scanf("%d",&N);
    sum=0;
    a[0]=0;
	for(int i = 1 ; i<=N ; i++){
		scanf("%d",&a[i]);
        sum += a[i];
	}
    memset(d,false,sizeof(d));
    d[0]=true;
    ans=1;
}

void Solve_Case(int i){
        for(int j = sum ; j>=0 ; j--){
			if(d[j]==true){
            	d[a[i]+j]=true;
            }
		}
}

void Print_ans(int i){
        for(int j = 1 ; j<=sum ; j++){
            if(d[j]==true){
            	ans++;
            }
		}
    printf("#%d %d\n",i,ans);
}

int main() {
	scanf("%d",&T);
	for(int i = 1 ; i<=T ; i++){
        
		Set_Case();
        for(int j = 1 ; j<=N ; j++){
			Solve_Case(j);
		}
		Print_ans(i);
		ans=0;
	}
	
	// your code goes here
	return 0;
}
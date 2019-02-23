#include <iostream>
#include <algorithm>
using namespace std;
int T;
int N, M;
int a[21][21];

void read_Case(){
	scanf("%d %d",&N,&M);
	for(int i = 1 ; i<=N ; i++){
		for(int j = 1 ; j<=M ; j++){
			scanf("%d",&a[i][j]);
		}
	}
}
void whos_best(){
	int people=0;
	int max_score=0;
	int score[21]={0,};
	for(int i = 1 ; i<=N ; i++){
		for(int j = 1 ; j<=M ; j++){
			if(a[i][j]==1){
				score[i]++;	
			}
		}
		if(max_score <= score[i]){
			max_score = score[i];
		}
	}
	for(int i = 1 ; i<=N ; i++){
		if(score[i]==max_score){
			people++;
		}
	}
	
	printf("%d %d\n", people, max_score);
}
int main() {
	scanf("%d",&T);
	
	for(int i = 1; i<=T ; i++){
		read_Case();
		printf("#%d ",i);
		whos_best();
	}
	return 0;
}
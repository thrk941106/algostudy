#include <iostream>
#include <string.h>
#include <set>
using namespace std;
int T;
char a[5][5];
int dx[] = {0,-1,0,1,0};
int dy[] = {0,0,1,0,-1};
bool d[5][5][5][5][5][5];
set<int> s;
int ans=0;
void setting_Case(){
	for(int i = 1 ; i <= 4 ; i++){
		for(int j=1 ; j<=4 ; j++){
			int temp;
			scanf("%d",&temp);
			a[i][j] = temp+'0';
		}
	}
}
void dfsd(int r, int c, string tse, int count, int tad[7]){
	int ad[7];
	string se = tse;
	copy(tad, tad + 7, ad);
	if(r<=4 && c<=4 && r>0 && c>0){
		if(d[ad[1]][ad[2]][ad[3]][ad[4]][ad[5]][ad[6]]==true){
			return;
		}else{
			d[ad[1]][ad[2]][ad[3]][ad[4]][ad[5]][ad[6]]=true;
			se += a[r][c];
		}
		if(count == 7){
			int intValue = atoi(se.c_str());
			pair<set<int>::iterator, bool> is_there;
			is_there=s.insert(intValue);

			if(is_there.second == true){
				ans++;
			}
			return;
		} else{
			for(int i=1 ; i<= 4 ; i++){
				ad[count]=i;
				dfsd(r+dx[i],c+dy[i],se,count+1,ad);
			}
		
		}
	
		
	}
}
int main() {
	scanf("%d",&T);
	for(int k = 1 ; k<=T; k++){
		setting_Case();
		for(int i = 1 ; i <= 4 ; i++){
			for(int j=1 ; j<=4 ; j++){
				int ad[7]={0,};
				string temp;
				temp = "";
				memset(d,false,sizeof(d));
				dfsd(i,j,temp,1,ad);
			}
		}
        printf("#%d %d\n",k,ans);
        ans = 0;
        s.clear();
	}
	
	// your code goes here
	return 0;
}
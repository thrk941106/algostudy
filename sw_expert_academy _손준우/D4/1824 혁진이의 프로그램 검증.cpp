#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
char a[21][21];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
		bool d[21][21][16][5];
int R,C;
int T,Test_n;
int memory=0;
int go_dir;
int ans=0;
int is_g=0;

void check(char temp){
	if(temp>='0' && temp<='9'){
		memory = temp -'0';
	} else if(temp == '+'){
		memory = (memory+1)%16;
	} else if (temp == '-'){
		memory = (memory+15)%16;
	} else {
		switch(temp){
			case '<' :
			go_dir = 3;
			break;
			case '>' :
			go_dir = 1;
			break;
			case '^' :
			go_dir = 0;
			break;
			case 'v' :
			go_dir = 2;
			break;
			
			case '_' :
			if(memory==0){
				go_dir = 1;
			} else{
				go_dir = 3;
			}
			break;
			
			case '|' :
			if(memory==0){
				go_dir = 2;
			} else{
				go_dir = 0;
			}
			break;
			case '.' :
			break;
		}
	}
	
}



void dfs(int x, int y){
	if(x<=0){
		x=R;
	}else if(x>R){
		x=1;
	} 
	if(y<=0){
		y=C;
	}else if(y>C){
		y=1;
	}
	if(d[x][y][memory][go_dir]){
		return;
	}
	if(ans!=0){
		return;
	}
	d[x][y][memory][go_dir] = true;
	char temp = a[x][y];

	if(temp=='@'){
		ans++;
		return;
	} else if(temp != '?'){
		check(temp);
		dfs(x+dx[go_dir],y+dy[go_dir]);
                    if(ans != 0){
            	return;
            }
	} else if(temp =='?'){
		for(int i = 0 ; i<4 ; i++){
            int memory_temp=memory;
            
			check(temp);
            go_dir = i;
			dfs(x+dx[i],y+dy[i]);
            if(ans != 0){
            	return;
            }
            memory= memory_temp;
		}
	}
}

void input_a(int R, int C){

		for(int i = 1 ; i<=R ; i++){
			for(int j =1 ; j<=C ; j++){
				cin >> a[i][j];
                if(a[i][j]=='@'){
                	is_g++;
                }
			}
	}    

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;
	for(int Test_n = 1 ; Test_n <=T ; Test_n++){

		cin >> R >> C;
		go_dir = 1;
		memory = 0;
		memset(d, false, sizeof(d));
		input_a(R, C);
        if(is_g==0){
        	cout <<'#' << Test_n  << " NO" <<'\n';
            ans = 0;
            continue;
        }
		dfs(1,1);
		if(ans!=0){
			cout <<'#' << Test_n  <<" YES" <<'\n';
		}else{
			cout <<'#' << Test_n  << " NO" <<'\n';
		}
		
		ans = 0;
	}
	return 0;
}
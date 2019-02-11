#include<iostream>
#include<algorithm>
using namespace std;
int N,L;
int a[101][101];
int b[101][101];
int ans=0;

void make_Road(int a[101][101], int i){
	bool c[101] = {false,};
	int temp = a[i][1];
    for (int j = 1; j <= N; j++){
        if(temp == a[i][j]){
            continue;
        }else {
            if(temp != a[i][j]-1 && temp != a[i][j]+1){
                return;
            } else if (a[i][j] < temp){
                for(int k=0 ; k<L ; k++){
                	if(j+k>N || c[j+k]){
                		return;
                	}
                	c[j+k] = true;
                    if(a[i][j]!=a[i][j+k]){
                        return;
                    }
                }
                j=j+L-1;
            }else {
                for(int k=1 ; k<=L ; k++){
                	if(j-k<=0 || c[j-k]){
                		return;
                	}
                	c[j-k] = true;
                    if(temp!=a[i][j-k]){
                        return;
                    }
                }
            }  
            temp = a[i][j];
        }
    }
    ans++;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> L;
    for(int i=1 ; i<=N ; i++){
        for(int j=1 ; j<=N ; j++){
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        make_Road(a, i);
        make_Road(b, i);
    }
    cout << ans;
 
}
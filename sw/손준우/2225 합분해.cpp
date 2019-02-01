#include<iostream>
#include<algorithm>
#define mod 1000000000
using namespace std;
int d[201][201];
int N, K;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for(int i=0 ; i<=N ; i++){
        d[1][i] = 1;
    }
    for(int i=2 ; i<=K ; i++){
    	d[i][0]=1;
        for(int j=1 ;  j<=N ; j++){
            d[i][j]=d[i][j-1] + d[i-1][j];
            d[i][j] %= mod;
        }
    }
    cout << d[K][N];
}
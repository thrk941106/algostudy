#include<iostream>
#include<algorithm>
#define mod 1000000000
using namespace std;
int n;
int d[101][10];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int j=1 ; j<=9 ; j++){
            d[1][j]=1;
    }
    
    for(int i=2 ; i<=n ; i++){
        d[i][0]=d[i-1][1]%mod;
        for(int j=1 ; j<=8 ; j++){
            d[i][j]=(d[i-1][j-1]+d[i-1][j+1])%mod;
        }
        d[i][9]=d[i-1][8]%mod;
    }
    long ans=0;
    for(int j=0 ; j<=9 ; j++){
            ans=ans+d[n][j];
    }
    cout << ans%mod;
    
    
}
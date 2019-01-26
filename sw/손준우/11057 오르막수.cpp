#include<iostream>
#include<algorithm>
#define mod 10007
using namespace std;
int n;
int d[1001][10];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int j=0 ; j<=9 ; j++){
            d[1][j]=1;
    }
    
    for(int i=2 ; i<=n ; i++){
        for(int j=0 ; j<=9 ; j++){
            for(int k=0 ; k<=j ; k++){
                d[i][j] = d[i][j] + d[i-1][k];
            }
            d[i][j] %=mod;
        }
    }
    long ans=0;
    for(int j=0 ; j<=9 ; j++){
            ans=ans+d[n][j];
    }
    cout << ans%mod;
    
    
}
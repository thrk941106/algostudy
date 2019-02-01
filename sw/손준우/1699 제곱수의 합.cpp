#include<iostream>
#include<algorithm>
int d[100001];
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    d[1]=1;
    
    for(int i=2 ; i<=n ; i++){
        int buf;
        buf = d[i-1];
        for(int j=2; j*j<=i ; j++){
            buf=min(buf,d[i-j*j]);
        }
        d[i] = buf+1;
    }
    cout << d[n];
    
}
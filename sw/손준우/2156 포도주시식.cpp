#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int d[10001][3];
int a[10001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
    }
    d[1][0]=0;
    d[1][1]=a[1];
    d[1][2]=0;
    for(int i=2 ; i<=n ; i++){
        d[i][0]=max(max(d[i-1][0],d[i-1][1]),d[i-1][2]);
        d[i][1]=d[i-1][0]+a[i];
        d[i][2]=d[i-1][1]+a[i];
    }
    cout << max(max(d[n][0],d[n][1]),d[n][2]) <<'\n';

}
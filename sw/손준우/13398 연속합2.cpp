#include<iostream>
#include<algorithm>
using namespace std;
int n;
int d[100001][2];
int a;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    
    cin >> a;
    d[1][0]=a;
    d[1][1]=0;
    int ans = a;
    for(int i=2 ; i<=n ; i++){
        cin >> a;
        d[i][0]=max(a,d[i-1][0]+a);
        d[i][1]=max(d[i-1][0],d[i-1][1]+a);
        ans = max(d[i][0],ans);
        ans = max(d[i][1],ans);
    }
     cout << ans;   
}
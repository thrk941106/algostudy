#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int d[100001];
int a[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> a[1];
    d[1]=a[1];
    int ans = d[1];
    for(int i=2 ; i<=n ; i++){
        cin >> a[i];
        d[i]=max(a[i],d[i-1]+a[i]);
        ans = max(d[i],ans);
    }
     cout << ans;   
}
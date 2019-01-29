#include<iostream>
#include<algorithm>
using namespace std;
int n;
int d[1001];
int d2[1001];
int a[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans=0;
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
        d[i]=1;
        d2[i]=1;
    }
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<i ; j++){
            if(a[j]<a[i]){
                d[i]=max(d[i],d[j]+1);
            }
            if(a[n-j+1]<a[n-i+1]){
                d2[n-i+1]=max(d2[n-i+1],d2[n-j+1]+1);
            }
        }
    }
    
    for(int i=1 ; i<=n ; i++){
        ans = max(ans, d[i]+d2[i]-1);
    }

    cout << ans;
}
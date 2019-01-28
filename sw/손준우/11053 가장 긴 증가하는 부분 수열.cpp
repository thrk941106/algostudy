#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
long d[1001];
int a[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long ans=0;
    cin >> n;

    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
        d[i]=1;
        for(int j=1 ; j<i ; j++){
            if(a[j]<a[i]){
                if(d[i]<d[j]+1){
                    d[i]=d[j]+1;
                }
            }
        }
        if(d[i]>ans){
            ans = d[i];
        }
    }
    cout << ans;
}
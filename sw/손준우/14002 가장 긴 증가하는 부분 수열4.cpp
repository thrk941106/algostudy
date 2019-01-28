#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
long d[1001];
int a[1001];
int p[1001];
void printa(int fi){
    if(p[fi]==fi){
    	cout << a[fi] << ' ';
        return;
    }
    printa(p[fi]);
    cout << a[fi] << ' ';
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long ans=0;
    int fi;
    cin >> n;

    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
        d[i]=1;
        p[i]=i;
        for(int j=1 ; j<i ; j++){
            if(a[j]<a[i]){
                if(d[i]<d[j]+1){
                    d[i]=d[j]+1;
                    p[i]=j;
                }
            }
        }
        if(d[i]>ans){
            ans = d[i];
            fi = i;
        }
    }
    cout << ans <<'\n';
    printa(fi);

}
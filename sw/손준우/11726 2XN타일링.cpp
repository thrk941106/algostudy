#include<iostream>
#include<algorithm>

using namespace std;
int n;
int a[1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    
    a[1]=1;
    a[2]=2;
    for(int i=3;i<=n;i++){
        a[i]=(a[i-1]+a[i-2])%10007;
    }
    cout << a[n];
        
    
}
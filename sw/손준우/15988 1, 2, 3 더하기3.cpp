#include<iostream>
#include<algorithm>

using namespace std;
int T;
long a[1000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    a[1]=1 % 1000000009;
    a[2]=2 % 1000000009;
    a[3]=4 % 1000000009;
    for(int i=4;i<=1000000;i++){
        a[i]=(a[i-1]+a[i-2]+a[i-3]) % 1000000009;
    }
    while(T--){
        int n;
        cin>>n;
        cout << a[n] << '\n';
    }
}
#include<iostream>
#include<algorithm>

using namespace std;
int T;
long a[100001][4];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    a[1][1]=1 % 1000000009;
    a[2][2]=1 % 1000000009;
    a[3][1]=1 % 1000000009;
    a[3][2]=1 % 1000000009;
    a[3][3]=1 % 1000000009;
    
    for(int i=4;i<=100000;i++){
        a[i][1]=(a[i-1][2]+a[i-1][3]) % 1000000009;
        a[i][2]=(a[i-2][3]+a[i-2][1]) % 1000000009;
        a[i][3]=(a[i-3][1]+a[i-3][2]) % 1000000009;
    }
    while(T--){
        int n;
        cin>>n;
        cout << (a[n][1]+a[n][2] + a[n][3])%1000000009 << '\n';
    }
}
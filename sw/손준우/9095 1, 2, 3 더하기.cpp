#include<iostream>
#include<algorithm>

using namespace std;
int T;
int a[12];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    a[1]=1;
    a[2]=2;
    a[3]=4;
    for(int i=4;i<=11;i++){
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }
    while(T--){
        int n;
        cin>>n;
        cout << a[n] << '\n';
    }
}
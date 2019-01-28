#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,T;
int d[100001][3];
int a[3][100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--){

        cin >> n;
        for(int i=1 ; i<=2 ; i++){
            for(int j=1 ; j<=n ; j++){
                cin >> a[i][j];
                d[j][i]=0;
            }
        }
        d[1][0]=0;
        d[1][1]=a[1][1];
        d[1][2]=a[2][1];
        for(int i=2 ; i<=n ; i++){
            d[i][0]=max(max(d[i-1][0],d[i-1][1]),d[i-1][2]);
            d[i][1]=max(d[i-1][0],d[i-1][2])+a[1][i];
            d[i][2]=max(d[i-1][0],d[i-1][1])+a[2][i];
        }
        cout << max(max(d[n][0],d[n][1]),d[n][2]) <<'\n';

        
    }

    
    
}
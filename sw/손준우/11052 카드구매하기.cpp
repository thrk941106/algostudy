#include<iostream>
#include<algorithm>
using namespace std;
int N;
int p[1001];
int a[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=1; i<=N ; i++){
        cin >> p[i];
    }
    
    for(int i=1; i<=N ; i++){
        for(int j=1 ; j<=i ; j++){
            if(a[i] < p[j]+a[i-j]){
                a[i]=p[j]+a[i-j];
            }
        }
    }
    cout << a[N];
    

}
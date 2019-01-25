#include<iostream>
#include<algorithm>

using namespace std;
int N;
int d[1000001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    d[1] = 0;
    for(int i = 2 ; i<=N ; i++ ){
        d[i]=d[i-1]+1;
        if(i%2 == 0 && d[i] > d[i/2]+1){
            d[i]=d[i/2]+1;    
        }
        if(i%3 == 0 && d[i] > d[i/3]+1){
            d[i]=d[i/3]+1;    
        }
    }
    cout << d[N];
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int d[100001];
bool c[100001];
int main(){
    int N, K;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    c[N]=true;
   
    deque<int> q;
    q.push_back(N);
    int x;
    while(!q.empty()){
        x = q.front();
        q.pop_front();
        if(x*2<=100000){
            if(c[x*2]==false){
                c[x*2]=true;
                q.push_front(x*2);
                d[x*2]=d[x];
            }
        }
       if(x+1<=100000){
            if(c[x+1]==false){
                c[x+1]=true;
                q.push_back(x+1);
                d[x+1]=d[x]+1;
            }
        }
        if(x-1>=0){
            if(c[x-1]==false){
                c[x-1]=true;
                q.push_back(x-1);
                d[x-1]=d[x]+1;
            }
        }
    }
    cout << d[K];
}
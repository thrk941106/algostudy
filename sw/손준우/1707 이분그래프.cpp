#include<iostream>
#include<vector>
#include<algorithm>
#define WHITE 0
using namespace std;
int is_bi = 0;

void dfs(vector<int> *v, int start, int *color, int c){
    color[start] = c;
    for(int i = 0 ; i < v[start].size() ; i++) {
        int next = v[start][i];
        if(color[next] == WHITE){
            dfs(v, next, color,3-c);
            if(is_bi != 0){
                return;
            }
        } else if(color[start] == color[next]) {
                cout << "NO" << '\n';
                is_bi++;
                return;
        }
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_cnt;
    cin >> test_cnt;

    while(test_cnt--) {
        int v, e;
        cin >> v >> e;
        vector<int> graph[v+1];
        int color[v+1];
        fill(color, color+v+1, WHITE);
        while(e--){
            int s, d;
			cin >> s >> d;
            graph[s].push_back(d);
            graph[d].push_back(s);
        }
        for(int i = 1 ; i <= v ; i++){
            if(color[i] == WHITE){
                dfs(graph,i,color,1);   
                if(is_bi!=0){
            	    break;
        	    } 
            }
        }
        if(is_bi==0){
            cout << "YES" <<'\n';
        } 
        is_bi=0;
    }
}
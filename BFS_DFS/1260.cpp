#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int> > v;

int n, m, start;

void dfs(int st){
    stack<int> s;
    vector<int> vst(n+1, 0);
    s.push(st);
    
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        if(vst[cur]){
            continue;
        }
        sort(v[cur].begin(), v[cur].end(), greater<int>());
        for(int i = 0 ; i < v[cur].size(); ++i){
            if(vst[v[cur][i]]){
                continue;
            }
            s.push(v[cur][i]);
        }
        vst[cur] = 1;
        cout << cur << " ";
    }
    cout << endl;
}

void bfs(int st){
    queue<int> q;
    vector<int> vst(n+1, 0);
    q.push(st);

    while(!q.empty()){
        
        int cur = q.front();
        q.pop();
        if(vst[cur]){
            continue;
        }
        sort(v[cur].begin(), v[cur].end());
        for(int i = 0 ; i < v[cur].size(); ++i){
            if(vst[v[cur][i]]){
                continue;
            }
            q.push(v[cur][i]);
        }
        vst[cur] = 1;
        cout << cur << " ";
        
    }
    cout << endl;
}

int main(){
    cin >> n >> m >> start;
    v.resize(n+1);
    for(int i = 0 ; i < m ; ++i){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }   


    dfs(start);
    bfs(start);
    
    return 0;
}


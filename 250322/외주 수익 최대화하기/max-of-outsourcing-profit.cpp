#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

// sol1 - dp
// int n;
// vector<pair<int,int> > v;

// int dp[16];

// int main() {
    
//     cin >> n;
//     v.resize(n);

//     for(int i = 0; i < n; ++i){
//         cin >> v[i].first >> v[i].second;
//     }

//     for(int i = 0; i < n; ++i){
        
//         if(i > 0) dp[i] = max(dp[i],dp[i-1]);

//         int t = v[i].first;
//         int p = v[i].second;

//         int end = i + t;
//         if(end <= n){
//             dp[end] = max(dp[end], dp[i] + p);
//         }

//     }
//     int ret = 0;
//     for(int i = 0 ; i <= n; ++i){
//         if(ret < dp[i]){
//             ret = dp[i];
//         }
//     }
//     cout << ret ;

    
//     return 0;
// }


//sol2-backTracking

int n;
int ret =0;
vector<pair<int,int>> v;


void dfs(int t, int p);

int main(){
    cin >> n;
    v.resize(n);

    for(int i = 0 ; i<  n ; ++i){
        cin >> v[i].first >> v[i].second;
    }

    dfs(0,0);
    cout << ret;

    return 0;
}



void dfs(int t, int p){
    if(t >= n){
        ret = max(ret , p);
        return;
    }

    dfs(t+1, p);

    if(t + v[t].first <= n){
        dfs(t+v[t].first, p+v[t].second);
    }
}

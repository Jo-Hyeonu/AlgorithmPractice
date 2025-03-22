#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<pair<int,int> > v;

int dp[16];

int main() {
    
    cin >> n;
    v.resize(n);

    for(int i = 0; i < n; ++i){
        cin >> v[i].first >> v[i].second;
    }

    for(int i = 0 ; i < n; ++i){
        if(i > 0) dp[i] = max(dp[i], dp[i-1]);

        int t = v[i].first, p = v[i].second;
        int end = i+t;
        if(end <= n ){
            dp[end] = max(dp[end], dp[i] + p);
        }
    }
    int ret = 0;
    for(int i = 0 ; i <= n; ++i){
        if(ret < dp[i]){
            ret = dp[i];
        }
    }
    cout << ret ;

    
    return 0;
}
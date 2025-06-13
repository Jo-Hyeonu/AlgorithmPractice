#include <iostream>

using namespace std;

int n;

int dp[41][2];


int main(){

    cin >> n;
    dp[0][1] = 0;
    dp[0][0] = 1;
    dp[1][1] = 1;
    dp[1][0] = 0;
    
    for(int i = 2; i <= 40; ++i){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }


    for(int i = 0 ; i < n; ++i){
        int tmp;
        cin >> tmp;
        cout << dp[tmp][0] << " " << dp[tmp][1] << "\n";
    }

    return 0;

}
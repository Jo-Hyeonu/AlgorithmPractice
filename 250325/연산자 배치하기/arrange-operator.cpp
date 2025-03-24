#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> num;
int op[3]; // + - *

int maxret = 1000000001;
int minret = 1000000001;

void dfs(int cnt, int op[3], int cur){
    if(cnt == n-1){
        if(maxret == 1000000001 || minret == 1000000001){
            maxret = cur;
            minret = cur;
            return;
        }
        if(cur > maxret){
            maxret = cur;
            return;
        }

        if(cur < minret){
            minret = cur;
            return;
        }

    }

    for(int i = 0 ; i< 3; ++i){
        if(op[i] > 0){
            op[i]--;
            if(i == 0){
                dfs(cnt+1, op, cur+num[cnt+1]);
            }
            else if(i == 1){
                dfs(cnt+1, op, cur-num[cnt+1]);
            }
            else{
                dfs(cnt+1, op, cur*num[cnt+1]);
            }
            op[i]++;
        }
    }
    
}


int main() {
    cin >> n;
    num.resize(n);
    for(int i =0  ;i < n ;++i){
        cin >> num[i];
    }

    for(int i = 0 ; i < 3; ++i){
        cin >> op[i];
    }

    

    dfs(0,op, num[0]);


    cout << minret << " " << maxret;

    return 0;
}
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string a,b;

/////////////////////////
//
//다시 풀기
//
////////////////////////

int arr[1001][1001];

int main(){

    cin >> a >> b;
    int n = a.size();
    int m = b.size();

    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i-1] == b[j-1]){
                arr[i][j] = arr[i-1][j-1] + 1;
            }
            arr[i][j] = max(arr[i][j], max(arr[i-1][j], arr[i][j-1]));
        }
    }
    
    cout << arr[n][m];
    return 0;
}
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int n, m;

int arr[1025][1025]; 
int prefix_sum[1025][1025];
queue<vector<int> > q;

int main(){
    cin >> n >> m;

    for(int i =0  ; i< n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            cin >> arr[i][j];
        }
    }

    for(int i = 0 ; i < m ; ++i){
        vector<int> temp;
        for(int j = 0 ; j < 4; ++j){
            int tmp;
            cin >> tmp;
            temp.push_back(tmp);
        }
        q.push(temp);
    }

    memset(prefix_sum, 0, sizeof(prefix_sum));

    prefix_sum[1][1] = arr[0][0];
    for(int i =1  ; i< n+1 ; ++i){
        for(int j = 1 ; j < n+1 ; ++j){
            prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];
            prefix_sum[i][j] += arr[i-1][j-1];
        }
    }   


    // for(int i = 0 ; i <  n+1 ; ++i){
    //     for(int j = 0 ; j < n+1 ; ++j){
    //         cout << prefix_sum[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    while(!q.empty()){
        vector<int> temp = q.front();

        int x1 = temp[0];
        int y1 = temp[1];
        int x2 = temp[2];
        int y2 = temp[3];

        int ret = prefix_sum[x2][y2];
        ret -= prefix_sum[x1-1][y2];
        ret -= prefix_sum[x2][y1-1];
        ret += prefix_sum[x1-1][y1-1];

        cout << ret << endl;

        q.pop();
    }

}
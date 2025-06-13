#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;


void func(int cur){
    if(cur == m){
        for(int i = 0 ; i < m ; ++i){
            cout<< arr[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = 1;  i <= n; ++i){
        if(cur == 0){
            arr[cur] = i;
            func(cur+1);
        }
        else{
            if(arr[cur-1] <= i){
                arr[cur] = i;
                func(cur+1);
            }
        }
       
    }
}

int main(){
    cin >> n >> m;

    arr.resize(m,0);

    func(0);
    return 0;
}


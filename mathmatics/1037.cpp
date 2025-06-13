#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int main(){
    cin >> n;
    v.resize(n);
    for(int i = 0 ; i < n ;++i){
        int tmp;
        cin >> tmp;
        v[i] = tmp;
    }

    sort(v.begin(), v.end());

    // for(int i = 0 ; i < n ;++i){
    //     cout << v[i];
    // }


    cout << v[0] * v[n-1];
    return 0;
}
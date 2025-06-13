#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n, s;

vector<int> v;



int main() {
    cin >> n >> s;
    v.resize(n+1);
    int min_len = n+1;
    v[0] = 0;
    for(int i = 1 ; i <= n ;++i){
        int tmp;
        cin >> tmp;

        v[i] = v[i-1] + tmp;
    }


    if(v[n] < s){
        cout << "0\n";
        return 0;
    }


    for(int i = 1 ; i <= n ; ++i){
        int target = v[i] - s;

        auto it = upper_bound(v.begin(), v.begin()+i, target); 
        // lower_bound 함수는 범위 안에서 val 이상인 첫 원소 위치(iterator) 반환해줌
        // iterator는  int 아니라서 v.begin()과 뺴서 int 자료형으로 활용가능
        if( it != v.begin()){
            it--;
            int idx = it - v.begin();
            if(v[i]-v[idx] >= s){
                if(min_len > i - idx){
                    min_len = i - idx;
                }
            }
            
        }

    }
    if(min_len == n+1){
        cout << "0\n";
    }
    else{
        cout << min_len << "\n";
    }
    
    return 0;
}
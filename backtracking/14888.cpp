#include <iostream>
#include <vector>

using namespace std;


int min_ret = 1000000000;
int max_ret = -1000000000;

int n ;
vector<int> v;
vector<int> op_seq;
int op[4];

void func(int k){
    if(k == (n-1)){
        int temp = v[0];
        for(int i = 0 ; i < n - 1; ++i){
            if(op_seq[i] == 0){
                temp = temp + v[i+1];
            }
            else if(op_seq[i] == 1){
                temp = temp - v[i+1];
            }
            else if(op_seq[i] == 2){
                temp = temp * v[i+1];
            }
            else if(op_seq[i] == 3){
                temp = temp / v[i+1];
            }
        }
        if(temp >= max_ret){
            max_ret = temp;
        }
        if(temp <= min_ret){
            min_ret = temp;
        }
        return;
    }

   for(int i = 0; i < 4 ; ++i){
        if(op[i] > 0){
            op_seq[k] = i;
            op[i]--;
            func(k+1);
            op[i]++;
        }
    }
    
}

int main() {
    cin >> n;
    v.resize(n);
    op_seq.resize(n-1, -1);
    for(int i = 0 ; i < n ; ++i){
        cin >> v[i];
    }

    for(int i = 0 ; i < 4 ; ++i){
        cin >> op[i];
    }

    func(0);

    cout << max_ret << endl;
    cout << min_ret << endl;

    return 0;
}
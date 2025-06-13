// #include <iostream>
// #include <queue>
// #include <time.h>

// using namespace std;


// long long n;
// long long max_n = 0;
// vector<long long> query;
// vector<long long> v;


// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n;
//     for(long long i = 0 ; i < n; ++i){
//         long long temp;
//         cin >> temp;
//         query.push_back(temp);
//         //cout << i << "\n";
//         if(temp > max_n){
//             max_n = temp;
//         }
//     }
    
//     v.resize(max_n*3 + 2, 0);
//     vector<long long> prefix(max_n+1, 0);
//     v[0] = 0;
//     v[1] = 1;
//     v[2] = 2;
//     prefix[0] = 0;
//     prefix[1] = 1;
//     prefix[2] = 3;
//     for(long long i = 1; i <= max_n ; ++i){
//         if(v[3*i] == 0){
//             v[3*i] = 2*v[i] + 2*v[i+1] + 1;
//         }
//         if(v[3*i + 1] == 0){
//             v[3*i + 1] = 2*v[i+2] - 1;
//         }
//         if(v[3*i+2] == 0){
//             v[3*i + 2] = 2 - 2*v[i+1] - 2*v[i+2];
//         }
//         prefix[i] = prefix[i-1] + v[i];
//     }

//     for(long long i = 0; i < query.size(); ++i){
//         cout << prefix[query[i]] << "\n";
//     }

//     return 0;
// }


#include <iostream>
#include <queue>
#include <time.h>

using namespace std;


long long n;
long long max_n = 0;
vector<long long> query;
vector<long long> v;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(long long i = 0 ; i < n; ++i){
        long long temp;
        cin >> temp;
        query.push_back(temp);
        //cout << i << "\n";
        if(temp > max_n){
            max_n = temp;
        }
    }
    
    v.resize(max_n*3 + 2, 0);
    vector<long long> prefix(max_n+1, 0);
    v[1] = 1;
    v[2] = 2;
    for(long long i = 1; i <= max_n ; ++i){
        v[3*i] = 2*v[i] + 2*v[i+1] + 1;
        v[3*i + 1] = 2*v[i+2] - 1;
        v[3*i + 2] = 2 - 2*v[i+1] - 2*v[i+2];
        prefix[i] = prefix[i-1] + v[i];
    }

    for(long long i = 0; i < query.size(); ++i){
        cout << prefix[query[i]] << "\n";
    }

    return 0;
}


// #include <iostream>
// #include <vector>
// #include <cmath>

// using namespace std;

// typedef long long ll;

// ll a, b;
// int cnt = 0;

// int main(){

//     cin >> a >> b;

//     ll limit = sqrt(b) + 1;

//     vector<bool> isPrime(limit + 1, true); // 벡터 (사이즈 , 초기값) 설정해서 선언!!
//     vector<ll> primes;

//     //에라토스테네스채로 소수 구하기
//     isPrime[0] = false;
//     isPrime[1] = false;
//     for(ll i = 2; i <= limit ; ++i){
//         if(isPrime[i]){
//             primes.push_back(i);
//             for(ll j = i*i; j <= limit ; j+=i){
//                 isPrime[j] = false;
//             }
//         }
//     }


//     for(ll j = 0 ; j < primes.size(); ++j){
//         ll i = primes[j];
//         ll temp = i*i;
//         while(temp <= b){
//             if(temp >= a){
//                 cnt++;
//             }
//             if(temp > b/i) break; // 오버플로우 방지
//             temp *= i;
//         }

//     }




//     cout << cnt << "\n";

//     return 0;
// }


#include <iostream>
#include <cmath>

using namespace std;


typedef long long ll;

ll a, b;
ll cnt = 0;


bool isPrime(ll n){
    if(n <= 1){
        return false;
    }
    if(n == 2){
        return true;
    }
    if(n%2 == 0){
        return false;
    }
    for(int i = 3 ; i <= sqrt(n); i+=2 ){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}



int main(){

    cin >> a >> b;

    for(int i = 2 ; i <= sqrt(b) ; i++){
        if(isPrime(i)){
            ll cur = i * i;

            while(cur <= b){
                if(cur >= a){
                    cnt++;
                }
                if(cur >= sqrt(b) / i) break;
                cur *= i;
            }
        }
    }


    cout << cnt;

    return 0;
}
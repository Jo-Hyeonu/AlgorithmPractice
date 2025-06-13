#include <iostream>
#include <stack>

using namespace std;


int n, m;

stack<int> s;

int func(int a, int b){

    int tmp = 1;

    if(a > b){
        int temp = b;
        b = a;
        a = temp;
    }

    for(int i = 2 ; i <= a; ++i){
        if(a % i == 0 && b % i == 0){
            tmp = i;
        }
    }
    return tmp;
}

int gcd(int a, int b) {
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}


int main(){
    cin >> n >> m;
    
    // int divisor = func(n,m);


    // int a = n / divisor;
    // int b = m / divisor;

    // cout << divisor << endl;
    // cout << divisor * a * b << endl;


    int gcdd = gcd(n,m);

    cout << gcdd << endl;
    cout << n*m/gcdd << endl;
    return 0;
}



// 최대공약수 -> 유클리드 호제법
// int gcd(int a, int b) {
//     while (b != 0) {
//         int r = a % b;
//         a = b;
//         b = r;
//     }
//     return a;
// }
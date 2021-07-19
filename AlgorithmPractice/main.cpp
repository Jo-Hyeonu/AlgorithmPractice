//
//  main.cpp
//  AlgorithmPractice
//
//  Created by 조현우 on 2021/07/18.
//

#include <iostream>

using namespace std;

int main() {
    int N;
    int result = 0;
    cin >> N;
    
    if( N < 100 ) {
        result = N;
    }
    else {
        result = 99;
        for(int i = 1; i < 10 ; i++){
            int temp = N;
            for(int j = i; (2*j-i) < 10; j++) {
                temp = i*100 + j*10 + (2*j-i);
                if( N >= temp){
                    result++;
                }
                else {
                    break;
                }
            }
            if( N < temp){
                break;
            }
        }
        
        for(int i = 9; i > 0 ; i--) {
            for(int j = i-1 ; (2*j-i) >= 0 ; j--) {
                int temp = i*100 + j*10 + (2*j-i);
                if(N >= temp) {
                    result++;
                }
            }
        }
    }
    cout << result << endl;
    return 0;
}

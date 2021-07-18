//
//  main.cpp
//  AlgorithmPractice
//
//  Created by 조현우 on 2021/07/18.
//

#include <iostream>

using namespace std;

int main() {
    int N, M;
    int a[100];
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++) {
        cin >> a[i];
    }

    int result = 0;

    for(int i = 0 ; i < N-2 ; i++){
        for(int j = i+1 ; j < N-1; j++){
            for(int k = j+1 ; k < N; k++) {
                int temp = a[i] + a[j] + a[k];
                if( temp <= M && temp > result){
                    result = temp;
                }
            }
        }
    }
    cout << result << endl;
}

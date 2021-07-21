//
//  main.cpp
//  AlgorithmPractice
//
//  Created by 조현우 on 2021/07/18.
//

#include <iostream>

using namespace std;

int N, M;
int a[51][51]; // N, M
int result = 2500;

int minV(int a, int b) {
    if (a <= b) {
        return a;
    }
    else {
        return b;
    }
}

int startW[8][8] = {{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0}};
int startB[8][8] = {{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1}};




int check(int n, int m) {
    int cntW = 0;
    int cntB = 0;
    for(int i = 0; i < 8 ; i++) {
        for(int j = 0; j < 8 ; j++){
            if(startW[i][j] != a[n+i][m+j]){
                cntW++;
            }
            if(startB[i][j] != a[n+i][m+j]){
                cntB++;
            }
        }
    }
    return min(cntW,cntB);
}



int main() {
    
    cin >> N >> M;
    for(int i = 0; i < N ; i++) {
        for(int j = 0 ; j < M ; j++){
            char temp;
            cin >> temp;
            if(temp == 'W'){
                a[i][j] = 0;
            }
            else {
                a[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < N - 7 ; i++) {
        for(int j = 0 ; j < M - 7 ; j++){
            int temp = check(i,j);
            if(temp < result){
                result = temp;
            }
        }
    }
    cout << result << endl;
    
}

//
//  main.cpp
//  AlgorithmPractice
//
//  Created by 조현우 on 2021/07/18.
//

#include <iostream>
#include <cstring>
using namespace std;

int N, M;
char a[51][51]; // N, M
int result = 0;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


int dfs(int n, int m) {
    int cnt = 0;
    if (a[n][m] == "W"){
        
    }
    else {
        
    }
    
    
}



int main() {
    
    cin >> N >> M;
    for(int i = 0; i < N ; i++) {
        for(int j = 0 ; j < M ; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < N - 7 ; i++) {
        for(int j = 0 ; j < M - 7 ; j++){
            if(dfs(i,j) < result){
                result = dfs(i,j);
            }
        }
    }
    cout << dfs << endl;
    
}

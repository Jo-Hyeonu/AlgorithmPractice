//
//  main.cpp
//  AlgorithmPractice
//
//  Created by 조현우 on 2021/07/18.
//

#include <iostream>
#include<cstring>
using namespace std;

bool check[51][51];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int field[51][51];
int M,N,K;

void dfs(int x, int y){
    check[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if(field[nx][ny] == 1) {
                if(!check[nx][ny]){
                    dfs(nx, ny);
                }
            }
        }
        else{
            continue;
        }
    }
}


int main(){
    int NOTC = 0;
    cin >> NOTC;
    while(NOTC--) {
        cin >> M >> N >> K;
        int result = 0;
        for(int i = 0; i < K; i++){
            int a, b;
            cin >> a >> b;
            field[b][a] = 1;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(field[i][j] == 1){
                    if(!check[i][j]){
                        result++;
                        dfs(i,j);
                    }
                }
            }
        }
        cout << result << endl;
        memset(check, false, sizeof(check));
        memset(field, 0, sizeof(field));
    }
}

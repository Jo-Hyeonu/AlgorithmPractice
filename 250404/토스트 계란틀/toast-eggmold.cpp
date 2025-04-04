#include <iostream>
#include <queue>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

int n, l , r;

int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, -1, 0, 1};

int board[51][51];
int same[2501];
int ret = 0;
int cnt  = 0;

void bfs(int x, int y);

int main() {
    cin >> n >> l >> r;

    for(int i =0  ;i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }


    while(){
        vector<vector<int>> check = bfs();

        if(cnt == n*n){
            break;
        }
        ret++;
    }
    
    cout << ret;

    return 0;
}

vector<vector<int>> bfs(void){

    vector<vector<int>> vst;
    vst.resize(n);
    for(int i = 0 ; i< n ;++i){
        vst[i].resize(n);
    }

    for(int i = 0 ; i < n ;++i){
        for(int j = 0 ; j < n; ++j){
            vst[i][j] = 0;
        }
    }

    cnt = 0;

    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ;++j){

            if(!vst[i][j]){
                cnt++;
                queue<pair<int, int>> q;
                q.push_back(make_pair(i,j));
                vst[i][j] = 1;

                int nume = board[i][j], deno = 1;

                while(!q.empty()){
                    int nx , ny;
                    for(int k = 0 ; k < 4; ++i){
                        nx = i + dx[k];
                        ny = j + dy[k];


                        if(nx < 0 || nx > n || ny < 0 || ny > n){
                            continue;
                        }

                        if(vst[nx][ny] > 0){
                            continue;
                        }

                        int diff = abs(board[nx][ny] - board[x][y]);
                        if(diff < l || diff > r ){
                            continue;
                        }

                        vst[nx][ny] = cnt;
                        q.push_back(make_pair(nx,ny));
                        nume += board[nx][ny];
                        deno++;
                    }
                }

                int tmp = nume / deno;

                for(int a = 0 ; a < n ; ++a){
                    for(int b = 0 ; b < n; ++b){
                        if(vst[a][b] == cnt) {
                            board[a][b] = tmp;
                        }
                    }
                }
            }
        }
    }
}
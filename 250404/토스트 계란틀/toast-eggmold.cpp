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

int bfs(void);

int main() {
    cin >> n >> l >> r;

    for(int i =0  ;i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    while(1){
        int check = bfs();

        if(check == 0){
            break;
        }
        ret++;
    }
    
    cout << ret;

    return 0;
}

int bfs(void){
    int ch = 0;
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

            if(vst[i][j] == 0){
                cnt++;
                queue<pair<int, int>> q;
                vector<pair<int, int>> group;
                q.push(make_pair(i,j));
                group.push_back(make_pair(i,j));
                vst[i][j] = cnt;

                int nume = board[i][j], deno = 1;

                while(!q.empty()){
                    pair<int,int> temp = q.front();
                    q.pop();

                    for(int k = 0 ; k < 4; ++k){
                        int nx , ny;
                        nx = temp.first + dx[k];
                        ny = temp.second + dy[k];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= n){
                            continue;
                        }

                        if(vst[nx][ny] != 0){
                            continue;
                        }

                        int diff = abs(board[nx][ny] - board[temp.first][temp.second]);
                        if(diff < l || diff > r ){
                            continue;
                        }
                        
                        ch = 1;
                        vst[nx][ny] = cnt;
                        q.push(make_pair(nx,ny));
                        group.push_back(make_pair(nx,ny));
                        nume += board[nx][ny];
                        deno++;
                    }
                }

                int tmp = nume / deno;

                for(int i = 0 ; i < group.size(); ++i){
                    board[group[i].first][group[i].second] = tmp;
                }
            }
        }
    }
    return ch;
}
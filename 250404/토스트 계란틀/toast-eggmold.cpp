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

bool bfs() {
    vector<vector<int>> vst(n, vector<int>(n, 0));
    int cnt = 0;
    bool isMoved = false;

    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            if(vst[i][j] == 0){
                cnt++;
                queue<pair<int, int>> q;
                vector<pair<int, int>> group;

                q.push({i,j});
                vst[i][j] = cnt;
                group.push_back({i, j});

                int nume = board[i][j], deno = 1;

                while(!q.empty()){
                    auto [x, y] = q.front();
                    q.pop();

                    for(int k = 0 ; k < 4; ++k){
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(vst[nx][ny] != 0) continue;

                        int diff = abs(board[nx][ny] - board[x][y]);
                        if(diff < l || diff > r) continue;

                        vst[nx][ny] = cnt;
                        q.push({nx, ny});
                        group.push_back({nx, ny});
                        nume += board[nx][ny];
                        deno++;
                        isMoved = true;
                    }
                }

                int newVal = nume / deno;
                for(auto [x, y] : group){
                    board[x][y] = newVal;
                }
            }
        }
    }

    return isMoved;
}

int main() {
    cin >> n >> l >> r;

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    int ret = 0;
    while (true) {
        if (!bfs()) break;
        ret++;  // 하루 증가
    }

    cout << ret << endl;
    return 0;
}

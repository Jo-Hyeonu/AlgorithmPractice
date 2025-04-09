#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

int n, m , k;

int board[11][11];
int tankTurn[11][11];

int findLastOne(void);
pair<int, int> findAttacker(void);
pair<int, int> findDeffencer(void);
void doAttack(pair<int,int> attacker, pair<int,int> deffencer);

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int ddx[8] = {0,1,0,-1,-1,-1,1,1};
int ddy[8] = {0,1,0,-1,-1,1,-1,1};

int main() {
    cin >> n >> m >> k;

    for(int i = 0; i < n ;++i){
        for(int j =0; j < m ; ++j){
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < n ;++i){
        for(int j =0; j < m ; ++j){
            tankTurn[i][j] = 0;
        }
    }
    int turn = 0;
    while(++turn <= k){
        
        pair<int, int> attacker = findAttacker();
        
        pair<int, int> deffencer = findDeffencer();

        if(attacker.first == deffencer.first && attacker.second == deffencer.second){
            break;
        }

        doAttack(attacker, deffencer);

        

    }

    cout << findLastOne();


    return 0;
}


int findLastOne(void){
    int tmp = 0;
    pair<int, int> tmpPos= {0,0};
    for(int j = 0 ; j < m ; ++j){
        for(int i = 0 ; i < n ; ++i){
            if(board[i][j] > tmp){
                tmp = board[i][j];
                tmpPos = {i,j};
            }
            else if(board[i][j] == tmp){
                if(tankTurn[tmpPos.first][tmpPos.second] < tankTurn[i][j]){
                    tmp = board[i][j];
                    tmpPos = {i,j};
                }
            }
        }
    }

    return tmp;
}

pair<int, int> findAttacker(void){
    int tmp = 5001;
    pair<int, int> tmpPos= {0,0};

    for(int i =0 ; i  <  n; ++i){
        for(int j =0 ;  j< m ; ++j){
            if(board[i][j] < tmp && board[i][j] != 0){
                tmp = board[i][j];
                tmpPos = {i,j};
            }
            else if(board[i][j] == tmp){
                if(tankTurn[i][j] >= tankTurn[tmpPos.first][tmpPos.second]){
                    tmp = board[i][j];
                    tmpPos = {i,j};
                }
            }

        }
    }
    board[tmpPos.first][tmpPos.second] += (n+m);
    return tmpPos;
}

pair<int, int> findDeffencer(void){
    int tmp = 0;
    pair<int, int> tmpPos= {0,0};
    for(int j = 0 ; j < m ; ++j){
        for(int i = 0 ; i < n ; ++i){
            if(board[i][j] > tmp){
                tmp = board[i][j];
                tmpPos = {i,j};
            }
            else if(board[i][j] == tmp){
                if(tankTurn[tmpPos.first][tmpPos.second] < tankTurn[i][j]){
                    tmp = board[i][j];
                    tmpPos = {i,j};
                }
            }
        }
    }
    return tmpPos;
}

vector<pair<int,int>> findPath(pair<int,int> attacker, pair<int,int> deffencer){
    int vst[11][11];
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m; ++j){
            vst[i][j] = 0;
        }
    }
    int path[11][11];
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m; ++j){
            path[i][j] = 5;
        }
    }
    queue<pair<int, int>> q;
    q.push(make_pair(attacker.first, attacker.second));
    vst[attacker.first][attacker.second] = 1;
    path[attacker.first][attacker.second] = -1;

    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        if(cur.first == deffencer.first && cur.second == deffencer.second){
            break;
        }

        for(int i= 0 ; i < 4 ;++i){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >=m){
                continue;
            }
            if(board[nx][ny] == 0){
                continue;
            }
            if(vst[nx][ny] != 0){
                continue;
            }
            vst[nx][ny] = vst[cur.first][cur.second] + 1;
            path[nx][ny] = i;
            q.push(make_pair(nx,ny));

        }
    }
    
    vector<pair<int,int>> p;
    int traceX = deffencer.first , traceY = deffencer.second;
    if(vst[traceX][traceY] == 0){
        return p;
    }


    while(path[traceX][traceY] != -1){
        p.push_back(make_pair(traceX,traceY));

        int dir = path[traceX][traceY];
        traceX = traceX - dx[dir];
        traceY = traceY - dy[dir];

    }
    p.push_back(make_pair(attacker.first, attacker.second));
    
    return p;
}

void doAttack(pair<int,int> attacker, pair<int,int> deffencer){
    int power = board[attacker.first][attacker.second];

    vector<pair<int,int>> minPath = findPath(attacker, deffencer);
    // for(int i =0 ; i < minPath.size() ; ++i){
    //     cout << minPath[i].first << " " << minPath[i].second << endl;
    // }
    if(minPath.size() == 0){
        board[deffencer.first][deffencer.second] -= power;

        for(int i = 0 ; i < 8; ++i){
            int sx = deffencer.first + ddx[i];
            int sy = deffencer.second + ddy[i];

            if(sx == attacker.first && sy == attacker.second){
                continue;
            }
            if(sx < 0){
                sx += n;
            }
            else if(sx >=n){
                sx -= n;
            }
            if(sy < 0){
                sy += m;
            }
            else if(sy >=m){
                sy -= m;
            }
            board[sx][sy] -= (power/2);
        }

        for(int i = 0 ; i < n; ++i){
            for(int j = 0 ; j < m ;++j){
                if(board[i][j] < 0){
                    board[i][j] = 0;
                }
                else if(board[i][j] > 0 && i != attacker.first && i != deffencer.first && j != attacker.second && j != deffencer.second){
                    board[i][j]++;
                }
            }
        }
        for(int i = 0 ; i < 8; ++i){
            int sx = deffencer.first + ddx[i];
            int sy = deffencer.second + ddy[i];

            if(sx == attacker.first && sy == attacker.second){
                continue;
            }
            if(sx < 0){
                sx += n;
            }
            else if(sx >=n){
                sx -= n;
            }
            if(sy < 0){
                sy += m;
            }
            else if(sy >=m){
                sy -= m;
            }
            board[sx][sy]--;
        }
        
    }
    else{ //razer attack
        // for(int i = 0 ; i < n ; ++i){
        //     for(int j = 0 ; j < m ; ++j){
        //         cout << board[i][j];
        //     }
        //     cout << endl;
        // }
        board[minPath[0].first][minPath[0].second] -= power;
        for(int i = 1 ; i < minPath.size()-1 ; ++i){
            //cout << minPath[i].first << " " << minPath[i].second <<endl;
            board[minPath[i].first][minPath[i].second] -= (power/2);
        }

        //복구
        for(int i = 0 ; i < n; ++i){
            for(int j = 0 ; j < m ;++j){
                if(board[i][j] < 0){
                    board[i][j] = 0;
                }
                else if(board[i][j] > 0){
                    pair<int,int> cur = {i,j};
                    if(find(minPath.begin(), minPath.end(), cur) == minPath.end()){
                        board[i][j]++;
                    }
                }
            }
        }
    }


}
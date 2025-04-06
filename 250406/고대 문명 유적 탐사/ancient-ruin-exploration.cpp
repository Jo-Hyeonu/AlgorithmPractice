#include <iostream>
#include <queue>


using namespace std;

int k, m;
int board[5][5];

int dx[4] ={0,1,0,-1};
int dy[4] ={1,0,-1,0};

queue<int> seq;

int rotate(void);

void printB(void){
    for(int i =0 ; i < 5; ++i){
        for(int j =0 ; j < 5; ++j){
            cout << board[i][j];
        }
        cout << endl;
    }

}

int main() {
    cin >> k >> m;

    for(int i =0 ; i < 5; ++i){
        for(int j =0 ; j < 5; ++j){
            cin >> board[i][j];
        }
    }

    for(int i = 0 ; i < m; ++i){
        int tmp;
        cin >> tmp;
        seq.push(tmp);
    }

    for(int i = 0 ; i  < k ; ++i){
        int end = rotate();
        if(end == 1){
            break;
        }
    }
    return 0;
}
int findUnion(void){ // 현재 연결가능한 유물 개수
    int ret = 0;
    int vst[5][5];
    for(int i = 0 ; i < 5 ; ++i){
        for(int j = 0 ; j  < 5 ; ++j){
            vst[i][j] = 0;
        }
    }

    for(int i = 0 ; i < 5 ; ++i){
        for(int j = 0 ; j < 5 ; ++j){
            if(vst[i][j] == 0){
                int curV = 1;
                queue<pair<int, int>> q;
                q.push(make_pair(i,j));
                vst[i][j] = 1;

                while(!q.empty()){
                    pair<int,int> cur = q.front();
                    q.pop();

                    for(int k = 0 ; k  <4 ; ++k){
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if(nx < 0 || nx >= 5 || ny < 0 || ny >=5){
                            continue;
                        }
                        if(vst[nx][ny] == 1){
                            continue;
                        }
                        if(board[nx][ny] != board[cur.first][cur.second]){
                            continue;
                        }

                        q.push(make_pair(nx,ny));
                        vst[nx][ny] = 1;
                        curV++;
                    }
                }
                if(curV >= 3){
                    ret += curV;
                }
            }
        }
    }
    return ret;
}

int rotate(void){

    int printV = 0;
    int maxV = 0;
    pair<int, int> maxPos = {1,1};
    int maxR = 0; // 1 : 90 , 2 : 180, 3 : 270

    for(int j = 1 ; j < 4 ; ++j){
        for(int i = 1 ; i  < 4 ; ++i){
            for(int r = 1; r <= 4 ;++r){
                int tmp = board[i-1][j];
                board[i-1][j] = board[i][j-1];
                board[i][j-1] = board[i+1][j];
                board[i+1][j] = board[i][j+1];
                board[i][j+1] = tmp;
                tmp = board[i-1][j+1];
                board[i-1][j+1] = board[i-1][j-1];
                board[i-1][j-1] = board[i+1][j-1];
                board[i+1][j-1] = board[i+1][j+1];
                board[i+1][j+1] = tmp;

                if(r != 4){
                    int tmpV = findUnion();
                    if(tmpV > maxV){
                        maxV = tmpV;
                        maxPos = {i,j};
                        maxR = r;
                    }
                    else if(tmpV == maxV){
                        if(r < maxR){
                            maxV = tmpV;
                            maxPos = {i,j};
                            maxR = r;
                        }
                    }
                       
                }

            }
        }
    }
    //printB();
    if(maxV == 0){
        return 1;
    }

    for(int r = 1; r <= maxR; ++r){
        int i = maxPos.first;
        int j = maxPos.second;
        int tmp = board[i-1][j];
        board[i-1][j] = board[i][j-1];
        board[i][j-1] = board[i+1][j];
        board[i+1][j] = board[i][j+1];
        board[i][j+1] = tmp;
        tmp = board[i-1][j+1];
        board[i-1][j+1] = board[i-1][j-1];
        board[i-1][j-1] = board[i+1][j-1];
        board[i+1][j-1] = board[i+1][j+1];
        board[i+1][j+1] = tmp;
    }

    // max 찾고 세팅
    int vst[5][5];
    while(1){
        //printB();
        for(int i = 0 ; i < 5 ; ++i){
            for(int j = 0 ; j < 5 ; ++j){
                vst[i][j] = 0;
            }
        }
        vector<pair<int,int>> v;
        
        for(int i = 0 ; i < 5 ; ++i){
            for(int j = 0 ; j < 5 ; ++j){
                if(vst[i][j] == 0){

                    int curV = 1;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    vst[i][j] = 1;

                    while(!q.empty()){
                        pair<int,int> cur = q.front();
                        q.pop();

                        for(int k = 0 ; k < 4 ; ++k){
                            int nx = cur.first + dx[k];
                            int ny = cur.second + dy[k];

                            if(nx < 0 || nx >= 5 || ny < 0 || ny >=5){
                                continue;
                            }
                            if(vst[nx][ny] == 1){
                                continue;
                            }
                            if(board[nx][ny] != board[cur.first][cur.second]){
                                continue;
                            }
                            q.push(make_pair(nx,ny));
                            vst[nx][ny] = 1;
                            curV++;
                        }
                    }
                    if(curV >= 3){
                        //printV += curV;
                        v.push_back(make_pair(i,j));
                    }
                }
            }
        }
        if(v.size() == 0){
            break;
        }
        for(int i = 0 ; i < 5 ; ++i){
            for(int j = 0 ; j < 5 ; ++j){
                vst[i][j] = 0;
            }
        }

        for(int i = 0 ; i < v.size(); ++i){
            int curV = 1;
            int curNum = board[v[i].first][v[i].second];
            queue<pair<int, int>> q;
            q.push(make_pair(v[i].first, v[i].second));

            while(!q.empty()){
                pair<int, int> cur = q.front();
                board[cur.first][cur.second] = 0;
                q.pop();

                for(int k = 0 ; k  <4 ; ++k){
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx < 0 || nx >= 5 || ny < 0 || ny >=5){
                        continue;
                    }
                    if(vst[nx][ny] == 1){
                        continue;
                    }
                    if(board[nx][ny] != curNum){
                        continue;
                    }
                    q.push(make_pair(nx,ny));
                    curV++;
                }
            }
            printV += curV;
        }


        // cout << "sdfasdfa\n";
        // printB();

        v.clear();
        for(int j = 0 ; j < 5 ;++j){
            for(int i = 4 ; i >= 0 ; --i){
                if(board[i][j] == 0){
                    board[i][j] = seq.front();
                    seq.pop();
                }
            }        
        }

        // cout << "after 0\n";
        // printB();

    }
    cout << printV << " ";
    return 0;
}
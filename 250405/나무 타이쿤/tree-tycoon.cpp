#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;


int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {1, 1, 0, -1, -1 ,-1, 0, 1};

int cx[4] = {-1, -1, 1, 1};
int cy[4] = {-1, 1, 1, -1};

int n, m;

int board[16][16];

vector<pair<int, int> > seq;
vector<pair<int, int> > supply;

void gross(int dir , int num);
void printboard(void){
    for(int i = 0 ; i<  n ;++i){
        for(int j = 0 ; j < n ;++j){
            cout << board[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    
    cin >> n >> m;

    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            cin >> board[i][j];
        }
    }

    supply.push_back(make_pair(n-2, 0));
    supply.push_back(make_pair(n-2, 1));
    supply.push_back(make_pair(n-1, 0));
    supply.push_back(make_pair(n-1, 1));

    seq.resize(m);
    for(int i = 0 ; i < m ; ++i){
        cin >> seq[i].first >> seq[i].second;
    }


    for(int i = 0 ; i < m ; ++i){
        //cout << " turn " << i << endl;
        gross(seq[i].first,  seq[i].second);
    }

    int ret = 0;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ;++j){
            ret += board[i][j];
        }
    }

    cout << ret;

    return 0;
}


void gross(int dir, int num){
    for(int i = 0 ; i < supply.size(); ++i){
        // cout << "new x ,y\n";
        // cout << supply[i].first << " " << dx[dir-1] << " " << num << endl;
        // cout << supply[i].second << " " << dy[dir-1] << " " << num << endl;
        int nx = supply[i].first + dx[dir-1]*num;
        int ny = supply[i].second + dy[dir-1]*num;

        if(nx < 0){
            nx += n;
        }
        else if(nx >= n){
            nx -= n;
        }
        if(ny < 0){
            ny += n;
        }
        else if(ny >= n){
            ny -= n;
        }

        supply[i].first = nx;
        supply[i].second = ny;
        board[nx][ny]++;
    }
    // move & gross
    queue<int> q;

    for(int i = 0 ; i < supply.size(); ++i){
        int cnt = 0;
        for(int j = 0 ; j  < 4 ; ++j){
            int nx = supply[i].first + cx[j];
            int ny = supply[i].second + cy[j];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n){
                continue;
            }
            
            if(board[nx][ny] >= 1) cnt++;
        }
        q.push(cnt);
    }

    for(int i = 0 ; i < supply.size(); ++i){
        int tmp = q.front();
        q.pop();

        board[supply[i].first][supply[i].second] += tmp;
        // if(board[supply[i].first][supply[i].second] >= 2){
        //     board[supply[i].first][supply[i].second] += 2;
        // }
    }
    vector<pair<int, int>> temp = supply;
    supply.clear();

    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            if(board[i][j] >= 2){
                int already = 0;
                for(int k = 0 ; k < temp.size(); ++k){
                    if(i == temp[k].first && j == temp[k].second){
                        already = 1;
                        break;
                    }
                }   

                if(already == 0){
                    board[i][j] -= 2;
                    supply.push_back(make_pair(i,j));
                }

            }
        }
    }

}
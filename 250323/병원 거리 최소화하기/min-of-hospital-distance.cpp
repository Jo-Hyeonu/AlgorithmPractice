#include <iostream>
#include <vector>

using namespace std;

int n, m;
int minDist = 5000;
int numOfhos = 0;

vector<pair<int, int > > hosPos;
int board[51][51];

void dfs(int start, vector<int> & combination);
int calDist(int hx, int hy, int px, int py);

int main() {
    cin >> n >> m;

    for(int i = 0 ; i < n; ++i){
        for(int j =0 ; j < n; ++j){
            cin >> board[i][j]; // 0 빈곳 , 1 사람 , 2 병원
            if(board[i][j] == 2){
                hosPos.push_back({i,j});
            }
        }
    }


    numOfhos = hosPos.size();

    vector<int> combination;

    dfs(0, combination);

    cout << minDist;

    return 0;
}

void dfs(int start, vector<int> & combination){
    if(combination.size() == m){
        int ret = 0;

        for(int i = 0 ; i <  n; ++i){
            for(int j = 0 ; j < n ;++j){
                if(board[i][j] == 1){
                    int min = 5000;
                    for(int k = 0 ; k < m; ++k){
                        int tmp = calDist(i,j,hosPos[combination[k]].first, hosPos[combination[k]].second);
                        if(tmp < min){
                            min = tmp;
                        }
                    }
                    ret += min;
                }
            }
        }

        if(ret < minDist){
            minDist = ret;
        }
        return;
    }


    for(int i = start; i < numOfhos; ++i){
        combination.push_back(i);
        dfs(i+1, combination);
        combination.pop_back();
    }

}


int calDist(int hx, int hy, int px, int py){

    int Dist = 0;

    if(hx >= px){
        Dist += (hx - px);
    }
    else{
        Dist += (px - hx);
    }

    if(hy >= py){
        Dist += (hy - py);
    }
    else{
        Dist += (py - hy);
    }

    return Dist;
}
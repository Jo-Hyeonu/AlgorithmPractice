#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

int n;
int numOfstudent;
int like[401][5];
int board[20][20];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

pair<int,int> findPos(int student[5]);

int main() {

    cin >> n;
    numOfstudent = n*n;

    for(int i = 0 ;i < numOfstudent ; ++i){
        cin >> like[i][0] >> like[i][1] >> like[i][2]  >> like[i][3]  >> like[i][4]; 
    }
    
    for(int i = 0 ; i< n ;++i){
        for(int j = 0; j < n; ++j){
            board[i][j] = 0;
        }
    }

    for(int i  = 0; i < numOfstudent ; ++i){
        pair<int,int> pos = findPos(like[i]);
        //cout << pos.first << pos.second << endl;
        board[pos.first][pos.second] = like[i][0];
    }



    // for(int i = 0 ; i< n ;++i){
    //     for(int j = 0; j < n; ++j){
    //         cout << board[i][j];
    //     }
    //     cout << endl;
    // }

    int ret = 0;

    for(int i = 0 ; i < n ;++i){
        for(int j = 0 ; j < n ; ++j){
            int now = board[i][j];

            for(int q = 0; q < numOfstudent; ++q){
                if(like[q][0] == now){
                    int howF = 0;
                    for(int k = 0 ; k < 4; ++k){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(x < 0 || x >= n || y < 0 || y>=n){
                            continue;
                        }
                        for(int o = 1 ; o <= 4 ; ++o){
                            if(board[x][y] == like[q][o]){
                                howF++;
                            }
                        }
                        
                    }
                    if(howF > 0){
                        ret += pow(10, howF-1);
                    }
                    
                    break;
                }
            }
        }
    }

    cout << ret;

    return 0;
}

pair<int, int> findPos(int student[5]){
    //cout << student[0] <<  student[1] <<  student[2] <<  student[3] <<  student[4] << endl;
    int maxF = -1;
    int maxE = -1;
    pair<int, int> ret = {0,0};

    for(int i = 0 ; i < n; ++i){
        for(int j =0 ; j < n; ++j){
            if(board[i][j] != 0){
                continue;
            }

            
            int nearE = 0;
            int nearF = 0;

            for(int k = 0 ; k < 4; ++k){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x < 0 || x >= n || y < 0 || y>=n){
                    continue;
                }
                if(board[x][y] == 0){
                    nearE++;
                }
                else{
                    for(int l = 1 ; l  < 5 ;l++){
                        if(board[x][y] == student[l]){
                            nearF++;
                            break;
                        }
                    }
                }
                
            }
            if(nearF > maxF){
                ret.first = i;
                ret.second = j;
                maxF = nearF;
                maxE = nearE;
            }
            else if(nearF == maxF){
                if(nearE > maxE){
                    ret.first = i;
                    ret.second = j;
                    maxF= nearF;
                    maxE = nearE;
                }
            }

        }
    }

    return ret;
}
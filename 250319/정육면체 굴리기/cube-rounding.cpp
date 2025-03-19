#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, DicePosX,DicePosY, k;

// 1: 동쪽, 2: 서쪽, 3: 북쪽, 4: 남쪽

// board가 0이면 주사위 바닥면 숫자 board에 새기기
// board가 0이 아니면 board에 쓰여진 수가 바닥면에 새겨지고 해당 칸은 0으로

int main() {
    cin >> n >> m >> DicePosX >> DicePosY >> k;
    vector<vector<int>> board(n, vector<int>(m));
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0;  j< m; ++j){
            cin >> board[i][j];
        }
    }
    vector<int> direction(k);
    for(int i = 0 ; i < k; ++i){
        cin >> direction[i];
    }

    int front = 0;
    int back = 0;
    int right = 0;
    int left = 0;
    int ceiling = 0;
    int floor = 0;

    for(int i = 0 ; i < k; ++i){
        if(direction[i] == 1){// 동쪽
            DicePosY++;
            if(DicePosY >= m){
                DicePosY--;
                continue;
            }
            int tmp = right;
            right = ceiling;
            ceiling = left;
            left = floor;
            floor = tmp;
        }
        else if(direction[i] == 2){ //서쪽
            DicePosY--;
            if(DicePosY < 0){
                DicePosY++;
                continue;
            }
            int tmp = ceiling;
            ceiling = right;
            right = floor;
            floor = left;
            left = tmp;
        }
        else if(direction[i] == 3){ //북쪽
            DicePosX--;
            if(DicePosX < 0){
                DicePosX++;
                continue;
            }
            int tmp = ceiling;
            ceiling = back;
            back = floor;
            floor = front;
            front = tmp;
        }
        else if(direction[i] == 4){ // 남쪽
            DicePosX++;
            if(DicePosX >= n){
                DicePosX--;
                continue;
            }
            int tmp = ceiling;
            ceiling = front;
            front = floor;
            floor = back;
            back = ceiling;
        }

        if(board[DicePosX][DicePosY] == 0){
            board[DicePosX][DicePosY] = floor;
        }
        else{
            floor = board[DicePosX][DicePosY];
            board[DicePosX][DicePosY] = 0;
        }
        cout << ceiling << endl;
    }


    return 0;
}
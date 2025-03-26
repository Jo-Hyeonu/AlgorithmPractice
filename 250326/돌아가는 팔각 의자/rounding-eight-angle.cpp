#include <iostream>
#include <vector>
#include <queue>
#include <utility>


using namespace std;



int v[4][8];
int isRotate[4];
queue<pair<int, int>> q;
int r;


void rotate(int num, int dir);
void check(int num);
void move(int num, int dir);


int main() {

    for(int i = 0 ; i <4 ; ++i){
        for(int j = 0; j < 8; ++j){
            cin>> v[i][j];
        }
    }

    cin >> r;

    for(int i = 0 ; i < r ; ++i){
        int t1, t2;
        cin >> t1 >> t2;

        q.push({t1,t2});
    }
    pair<int,int> cur = q.front();
    while(!q.empty()){
        
        q.pop();

        for(int i = 0 ; i < 4; ++i){
            isRotate[i] = 0;
        }
        rotate(cur.first, cur.second);
    }
    int ret = 0;

    for(int i = 0 ; i < 4 ;++i){
        //cout << v[i][0] << endl;
    }
    
    return 0;
}

void check(int num){
    cout << "call";
    int left, right;

    if(num-1 >= 0){
        left = num-1;
        if(v[num][6] != v[left][2]){
            isRotate[left] = 1;
            check(left);
        }
    }

    if(num+1 < 4){
        right = num+1;
        if(v[num][2] != v[right][6]){
            isRotate[right] = 1;
            check(right);
        }
    }

    return;
}

void move(int num, int dir){
    int tmp = v[num][0];
    if(dir == 1){
        v[num][0] = v[num][7];
        v[num][7] = v[num][6];
        v[num][6] = v[num][5];
        v[num][5] = v[num][4];
        v[num][4] = v[num][3];
        v[num][3] = v[num][2];
        v[num][2] = v[num][1];
        v[num][1] = tmp;
    }
    else if(dir == -1){
        v[num][0] = v[num][1];
        v[num][1] = v[num][2];
        v[num][2] = v[num][3];
        v[num][3] = v[num][4];
        v[num][4] = v[num][5];
        v[num][5] = v[num][6];
        v[num][6] = v[num][7];
        v[num][7] = tmp;
    }

    return;
}

// 0 N, 1 S, 1 cw, -1, rcw
void rotate(int num, int dir){
    isRotate[num] = 1;

    check(num);

    for(int i = 0 ; i <4 ;++i){
        cout << isRotate[i];
    }

    if(num %2 == 0){
        isRotate[1] *= (-1*dir);
        isRotate[3] *= (-1*dir);
    }
    else{
        isRotate[0] *= (-1*dir);
        isRotate[2] *= (-1*dir);
    }

    for(int i = 0 ; i < 4 ; ++i){
        move(i, isRotate[i]);
    }

    return;
}
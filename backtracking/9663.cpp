#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, -1, 1};


int n;
int cnt = 0;
int arr[16][16];

void printB(void){
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ;++j){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void mark(int x, int y, int cur){
    for(int i = 0 ; i < n; ++i){
        if(arr[x][i] == 0){
             arr[x][i] = cur;
        }
       
    }
    for(int i = 0 ; i < n; ++i){
        if(arr[i][y] == 0){
             arr[i][y] = cur;
        }
    }

    for(int i = 0 ; i < 4; ++i){
        int nx = x, ny = y;
        while(1){
            nx += dx[i];
            ny += dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n){
                break;
            }
            if(arr[nx][ny] == 0){
                arr[nx][ny] = cur;
            }   
        }
    }
    return;
}

void unmark(int x, int y, int cur){
    for(int i = 0 ; i < n; ++i){
        if(arr[x][i] == cur){
            arr[x][i] = 0;
        }
        
    }
    for(int i = 0 ; i < n; ++i){
        if(arr[i][y] == cur){
            arr[i][y] = 0;
        }
    }

    for(int i = 0 ; i < 4; ++i){
        int nx = x, ny = y;
        while(1){
            nx += dx[i];
            ny += dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n){
                break;
            }
            if(arr[nx][ny] == cur){
                arr[nx][ny] = 0;
            }
            
        }
    }
    return;
}

bool col[15];
bool diag1[30];
bool diag2[30];

void func(int cur){
    //printB();
    if(cur == n+1){
        
        cnt++;
        return;
    }


    // for(int i = 0 ; i < n ;++i){
    //     for(int j = 0 ; j < n; ++j){
    //         if(arr[i][j] == 0){
    //             mark(i,j,cur);
    //             //cout << "call func at" << i << "," <<j<<endl;
    //             func(cur+1);
    //             unmark(i,j,cur);

    //         }
    //     }
    // }
    
    for(int i = 0 ; i < n ; ++i){
        if(col[i] || diag1[cur + i] || diag2[cur - i + n -1]) continue;

        col[i] = diag1[cur+i] = diag2[cur-i+n-1] = true;
        func(cur+1);
        col[i] = diag1[cur+i] = diag2[cur-i+n-1] = false;
    }

    return;
}


int main(){

    cin >> n;

    memset(arr, 0, sizeof(arr));

    func(1);

    cout << cnt;
    return 0;
}
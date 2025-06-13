#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n, m;
vector<pair<int,int> > river;
vector<int> cango;
int cost;
int numOfbridge = 0;

bool isRiver(int x, int y){

    for(int i = 0 ; i < river.size() ;++i){
        if(river[i].first == x + 1 && river[i].second == y + 1){
            return true;
        }
    }
    return false;
}

bool already(int x, int y){

    if(cango[x] && cango[y]){
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i = 0 ; i < m ;++i){
        int x,y;
        cin >> x >> y;
        river.push_back(make_pair(x ,y));
    }
    cango.resize(n,0);
    for(int i = 0 ; i < n ;++i){
        for(int j = i + 1; j < n; ++j){
            if(numOfbridge == n-1){
                cout << cost << "\n";
                return 0;
            }
            if(already(i,j)){
                continue;
            }
            if(isRiver(i,j)){
                continue;
            }
            cango[i] = 1;
            cango[j] = 1;
            numOfbridge++;
            cost += (i+j+2);
        }
    }

    return 0;

}

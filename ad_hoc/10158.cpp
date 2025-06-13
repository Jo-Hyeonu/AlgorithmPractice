#include <iostream>
#include <utility>

using namespace std;

int w, h, t;

int main(){
    cin >> w >> h;
    pair<int,int> st;
    cin >> st.first >> st.second;
    cin >> t;

    int dirx = 1, diry = 1;
    while(t--){
        st.first += dirx;
        st.second += diry;

    }   


}
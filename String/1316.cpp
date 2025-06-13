#include <iostream>
#include <vector>

using namespace std;

int n, cnt = 0;

int main(){

    cin >> n;

    while(n--){
        vector<bool> alpa(27,false);
        string temp;
        cin >> temp;
        int len = temp.length();

        if(len == 1){
            cnt++;
            continue;
        }

        for(int i = 0 ; i < len; ++i){
            int st = i;
            int ed = i;
            while(temp[st] == temp[ed]){
                ed++;
            }
            ed--;

            if(!alpa[temp[st] - 'a']){
                alpa[temp[st] - 'a'] = true;
                i = ed;
            }
            else{
                cnt--;
                break;
            }
        }
        cnt++;
    }

    cout << cnt;

    return 0;
}
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;
string temp;

int main(){
    cin >> n;

    while(n--){
        cin >> temp;
        bool ret = true;
        int len = temp.length();
        stack<char> s;

        for(int i = 0 ; i < len ; ++i){
            if(temp[i] == '('){
                s.push(temp[i]);
            }
            else{
                if(!s.empty()){
                    s.pop();
                }
                else{
                    ret = false;
                    break;
                }

            }
        }

        if(!s.empty()){
            ret = false;
        }

        if(ret){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
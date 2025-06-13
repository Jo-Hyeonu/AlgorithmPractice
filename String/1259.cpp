#include <iostream>
#include <cstring>

using namespace std;

string input;

bool isPalindrom(string n){
    int len = n.length();

    int half = len / 2;

    for(int i = 0 ; i <= half ;  ++i){
        if(n[i] != n[len-1-i]){
            return false;
        }
    }
    return true;
}

int main(){

    while(1){
        cin >> input;

        if(input == "0"){
            break;
        }

        if(isPalindrom(input)){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }

    }
    
    return 0;
}


#include <iostream>
#include <cstring>


using namespace std;

char s[101];

int M = 0, O = 0, B = 0, I = 0, S = 0;

int main(){

    cin >> s;

    for(int i = 0 ; i < strlen(s); ++i){
        if(s[i] == 'M'){
            M = 1;
        }
        else if(s[i] == 'O'){
            O = 1;
        }
        else if(s[i] == 'B'){
            B = 1;
        }
        else if(s[i] == 'I'){
            I = 1;
        }
        else if(s[i] == 'S'){
            S = 1;
        }   
    }

    if(M && O && B && I && S){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}
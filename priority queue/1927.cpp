#include <iostream>
#include <queue>


using namespace std;

int n;

priority_queue<int, vector<int>, greater<int> > pq;



int main(){


    ios::sync_with_stdio(false);
    cin.tie(0);



    cin >> n;
    int tmp;
    while(n--){
        cin >> tmp;

        if(tmp == 0){
            if(pq.empty()){
                cout << "0\n";
            }
            else{
                cout << pq.top() << endl;
                pq.pop();
            }
            
        }
        else{
            pq.push(tmp);
        }
        
    }
    return 0;
}
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
    deque<int> dq;
    int N;

    cin >> N;

    while(N--) {
        string str;
        cin >> str;

        if(str=="push_front") {
            int X;
            cin >> X;
            dq.push_front(X);
        }

        else if(str=="push_back") {
            int X;
            cin >> X;
            dq.push_back(X);
        }

        else if(str=="pop_front") {
            if(!dq.empty()) {
                cout << dq.front() <<"\n";
                dq.pop_front();
            }
            else
                cout << "-1\n";
        }

        else if(str=="pop_back") {
            if(!dq.empty()){
                cout << dq.back()<<"\n";
                dq.pop_back();
            }
            else
                cout << "-1\n";
        }

        else if(str=="size") {
            cout << dq.size() <<"\n";
        }

        else if(str=="empty") {
            cout << dq.empty() <<"\n";
        }

        else if(str=="front") {
            if(!dq.empty()) {
                cout << dq.front() <<"\n";
            }
            else
                cout << "-1\n";
        }

        else if(str=="back") {
            if(!dq.empty()) {
                cout << dq.back() <<"\n";
            }
            else
                cout << "-1\n";
        }
    }

    return 0;
}
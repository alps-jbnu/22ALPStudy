#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        deque<int> dq;
        bool isReverse = false;
        bool isError = false;
        string p, arr, temp;
        int n;

        cin >> p >> n >> arr;
        for (int i = 0; i < arr.length(); i++) {
            if (!isdigit(arr[i])) {
                if (!temp.empty()) {
                    dq.push_back(stoi(temp));
                    temp = "";
                }
            }
            else temp += arr[i]; // isdigit을 이용해 해당 문자열의 값이 정수인지 판변 후 true일 경우 temp문자열에 연산자 오버로딩
        }

        for (int i = 0; i < p.length(); i++) {
            if (p[i] == 'R') {
                if (isReverse) isReverse = false;
                else isReverse = true;
            }
            else if (p[i] == 'D') {
                if (dq.empty()) { // deque이 empty인 경우에 'D'인 경우 error 처리
                    cout << "error\n";
                    isError = true;
                    break;
                }
                /*
                deque을 사용하지 않으면 실제 모든 값을 뒤집는 코드를 작성해야 하는데
                deque을 사용함으로 인해서 isReverse의 여부에 따라 pop_back()을 
                할지 pop_front()을 할지만 파악하면 된다.
                */
                if (isReverse) dq.pop_back();
                else dq.pop_front();
            }
        }

        if (!isError) {
            cout << "[";
            if (isReverse && !dq.empty()) {
                for (auto its = dq.rbegin(); its != dq.rend(); its++) {
                    if (its == dq.rend() - 1) cout << *its;
                    else cout << *its << ',';
                }
            }
            else if(!isReverse && !dq.empty()){
                for (auto its = dq.begin(); its != dq.end(); its++) {
                    if (its == dq.end() - 1) cout << *its;
                    else cout << *its << ',';
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}

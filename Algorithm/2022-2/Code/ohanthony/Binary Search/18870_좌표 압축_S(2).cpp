#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int arr[1000005];
vector<int> temp, result;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        temp.push_back(arr[i]);
    }
    sort(temp.begin(), temp.end()); // 오름차순으로 정렬

    for(int i = 0; i < n; i++){ // 중복된 숫자는 제거함
        if(i == 0 || temp[i-1] != temp[i]){
            result.push_back(temp[i]);
        }
    }

    for(int i = 0; i < n; i++){
        cout << lower_bound(result.begin(), result.end(), arr[i]) - result.begin() << " ";
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int n, m;
int arr[10];
bool isused[10];

void func(int num){
    if(num == m){ // base condition, m개를 모두 택했을때
        for(int i = 0; i < m; i++) cout << arr[i] << ' '; //  그동안 arr에 기록해둔 수를 출력
        cout << '\n';
        return ;
    }

    int st = 1;
    if(num != 0) st = arr[num-1] + 1;

    for(int i = st; i <= n; i++){ // 1~n까지 모든 수에 대해 파악
        if(!isused[i]){ // 아직 i가 사용되지 않을 경우에만 들어감
            arr[num] = i;
            isused[i] = true;
            func(num+1); // 다음 수를 정하러 한 단계 더 들어감,  주어진 조건 m까지
            isused[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    func(0);
    return 0;
}
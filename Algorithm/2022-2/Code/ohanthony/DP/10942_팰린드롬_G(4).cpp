#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int num[2005];
bool dp[2005][2005]; // x에서부터 y까지 Pa 여부에 대한 점화식

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N; // 수열의 크기
    for(int i = 1; i <= N; i++) {
        cin >> num[i];
        dp[i][i] = true; // st==en인 경우 Pa 성림

        // index가 연속해서 같은 숫자일 경우 역시 Pa 성립
        if(i != 1 && num[i-1] == num[i]) dp[i-1][i] = true;
    }

    for(int i = 2; i < N; i++){
        for(int j = 1; i + j <= N; j++){
            if(num[j] == num[j+i] && dp[j+1][j+i-1]){
                dp[j][j+i] = true;
            }
        }
    }

    int M;
    cin >> M; // 질문 개수
    while(M--){
        int st, en;
        cin >> st >> en; // st번째 수부터 en번째 까지
        cout << dp[st][en] << '\n';
    }
    return 0;
}

/*
1. 시간복잡도 고려를 안하고 접근한다면 매 경우마다 임의의 vector에다가 해당 구간을 저장하고 reverse해 팰린드롬(이하 Pa) 여부를 판단할 수 있다.
while(M--){
        bool isPalindrome = true;
        int st, en;
        cin >> st >> en; // st번째 수부터 en번째 까지

        vector<int> temp(2005);
        for(int i = st; i <= en; i++) temp[i] = num[i];

        reverse(temp.begin()+st, temp.begin()+en+1);

        for(int i = st; i <= en; i++){
            if(temp[i] != num[i]){
                isPalindrome = false;
                cout << "0\n";
                break;
            }
        }

        if(isPalindrome) cout << "1\n";
    }
하지만 시간복잡도는 질문의 개수 1,000,000이고 수열의 크기 2000이므로 최대 20억번 연산 필요하므로 dp로 접근

2. Pa일 경우를 표로 작성해 규칙을 파악

 index: 1(1) 2(2) 3(1) 4(3) 5(1) 6(2) 7(1)
 -----------------------------------------
    1   o    x    o    x    x    x    o
    2        o    x    x    x    o    x
    3             o    x    o    x    x
    4                  o    x    x    x
    5                       o    x    o
    6                            o    x
    7                                 o

=> 이를 통해 st~en이 Pa이면 st+1 ~ en-1도 마찬가지로 Pa
   즉, arr[st] == arr[en], dp[st+1][en-1] == true 만족해야한다.
*/
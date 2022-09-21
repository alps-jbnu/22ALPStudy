#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int L, C;
char alpha[20];
char arr[20];
bool isused[20];
bool isCollection; // 최소 모음의 개수 판별 여부
int isConsonat;    // 최소 자음의 개수 판별 여부

void func(int n) {
    if (n == L) {
        for (int i = 0; i < L; i++) { // base condition 조건 만족했을때 최소 모음 1개, 최소 자음 2개 여부를 판단
            if (isCollection && isConsonat >= 2) break;

            if (arr[i] == 'a' || arr[i] == 'i' || arr[i] == 'e' || arr[i] == 'o' || arr[i] == 'u') isCollection = true;
            else isConsonat++;
        }

        if (isConsonat >= 2 && isCollection) {
            for (int i = 0; i < L; i++) {
                cout << arr[i];
            }
            cout << '\n';
        }
       
        isCollection = false;
        isConsonat = 0;
        return;
    }

    for (int i = 0; i < C; i++) {
        if (arr[n - 1] > alpha[i]) continue;

        if (!isused[i]) {
            isused[i] = true;
            arr[n] = alpha[i];
            func(n + 1);
            isused[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> L >> C;
    for (int i = 0; i < C; i++) cin >> alpha[i];
    sort(alpha, alpha + C);
    func(0);
    return 0;
}
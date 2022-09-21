#include <bits/stdc++.h>
using namespace std;

int N, d, k, c, result;
/*
- N: 접시의 수
- d: 초밥의 가짓수
- k: 연속해서 먹는 접시의 수
- c: 쿠폰 번호
*/

int dish[30005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; i++) cin >> dish[i];

    for (int st = 0; st < N; st++) {
        int isEat[3005] = { 0, };
        int flag = 0;
        int coupon = 1; // 쿠폰 스시가 있는지 확인

        for (int en = st; en < st + k; en++) {
            if (isEat[dish[en % N]] == 1) flag++; // 이미 먹은 초밥일 경우 중복 표시
            else isEat[dish[en % N]] = 1; // 처음 먹은 초밥일 경우 체크

            if (dish[en % N] == c) coupon = 0;
        }

        result = max(result, k - flag + coupon);
    }

    cout << result;
    return 0;
}
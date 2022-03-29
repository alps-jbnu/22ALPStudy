#include<iostream>

using namespace std;

long long start[10001];	// 처음 시작하는 ai+aj 저장
long long stop[10001];		// 끝나는 bi+bj 저장
long long a_i[10001];
long long b_i[10001];

int main()
{
	ios::sync_with_stdio, cin.tie(0);

	// input
	int N, M;
	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		int temp1, temp2;
		cin >>  temp1 >> temp2;
		a_i[temp1]++;
		b_i[temp2]++;
	}

	for (int i = 0;i <= M;i++) {
		for (int j = 0;j <= M;j++) {
			start[i+j] += a_i[i] * a_i[j];
			stop[i+j] += b_i[i] * b_i[j];
		}
	}

	/*for (int i = 0;i < 11;i++) {
		cout << stop[i] << " ";
	}*/

	// output (temp에 start배열과 stop배열에 저장해둔것을 이용하여 값을 구한다)
	long long temp = 0;
	for (int i = 0;i < 2 * M + 1;i++) {
		temp += start[i];
		cout << temp << '\n';
		temp -= stop[i];
	}

	return 0;
}
/*
	입력:
	1. N M		// N간격의 개수 M최대값
	2. ai, bi N번

	0 <= M <=5,000

	출력:
	2M+1개의 출력, 0~2M 의 범위에서 각 K의 값 각각

	풀이: 모든 경우의수를 배열에 저장한다.	// M이 5,000 까지라 최대 10,000 임

	but 배열을 두개 만들어서 (2, 10)이면
	추가하는 배열[2] ++;
	빼는 배열[10]++;

	K 0~2M+1 까지 확인 하는데
	K의 값을 배열의 인덱스로 start배열에서 더하고 stop배열에서 빼는 연산을 통해
	ai+aj <= k <= bi+bj 에서 k의 개수를 구할 수 있다. 

	{
	입력받은 수를 변환시킬때( start, stop배열에 넣을떼 시간초과가 나온다)

	해결하는 방법:
	
	
	
	}
*/

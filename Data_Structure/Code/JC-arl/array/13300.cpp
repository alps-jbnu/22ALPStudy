#include<iostream>
using namespace std;

int main(void)
{
	
	int N, S, K, Y, count = 0;//s-성별, y-학년
	int arr[2][7] = { 0 };
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> S >> Y;
		arr[S][Y]++;
	}
	for (int j = 0; j < 2; j++)
	{
		for (int i = 1; i <= 6; i++)
		{
			if (arr[j][i] % K)//나누어 떨어지지 않을 때
				count = count + ((arr[j][i]) / K) + 1;
			else 
				count = count + (arr[j][i] / K);
		}
	}
	cout << count;
	return 0;
}

/*2박3일 남-남, 여-여 방배정
 1~6학년까지, 한방에 한명 배치가능,같은 학년끼리만 배치
 한방에 최대인원수-k 방의 최소 개수 출력
 
 입력-참가 학생수-N , 방 최대 인원-K
 +성별S 와 학년Y 제시
 S는 0,1  0-여자, 1-남자;
 출력-최소한의 방 수
*/
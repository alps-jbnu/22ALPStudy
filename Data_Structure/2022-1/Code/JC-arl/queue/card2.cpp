#include<iostream>
#include<queue>
using namespace std;
int main(void)
{
	int n;
	queue<int> qu;
	cin >> n;
	for (int j = 1; j <= n; j++)
	{
		qu.push(j);
	}
	for (int i = 1;; i++)
	{
		if (qu.size() == 1)
			break;
		if (i % 2 == 0)//짝수
		{
			int num;
			num = qu.front();
			qu.push(num);
			qu.pop();

		}
		else			//홀수
		{
			qu.pop();
		}
	}
	cout << qu.front();

	return 0;
}

/*
입력: 첫째줄에 정수 1~n까지의수
출력: 버리고 맨아래에 옮기고 해서 마지막 남은 카드의 번호 출력
-큐는 선입선출이고 앞,뒤로 접근할 수 있으니 큐를 사용한다.
먼저 맨위를 1번 front_point 맨 아래를 n번 rear_point 해서
버리는것은 front로 접근한뒤 pop 그리고 그다음 맨위의 카드도 front로 
접근한뒤 변수에 저장 후 rear에 넣고 front pop 해서 size가 1일때
남은 마지막 출력

1.n을 입력

2.무한 반복문을 돌려 queue의 사이즈가 1일떄 브레이크

3.맨위를 front 맨아래를rear 

4.1부터 먼저 무조건 버려짐 그다음 3
따라서 홀수번부터 버려짐 그리고 짝수번이 버려짐
=> 반복변수 가 1일때 홀수번만 버려짐
*/
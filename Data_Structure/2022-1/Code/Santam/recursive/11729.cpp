#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Hanoi(int start, int fin, int n)
{
	if (n == 1) cout << start << " " << fin <<"\n";
	else
	{
		Hanoi(start, 6-start-fin, --n); // 6-start-fin는 start,fin위치를 제외한 위치, 이 코드로 가장 큰원판을 제외한 원판을 목적지가 아닌 다른 위치에 잠시 놓는다.
		cout << start << " " << fin <<"\n"; //가장 큰원판 목적지로 옮김
		Hanoi(6 - start - fin, fin, n); // 임시로 옮겨논 원판들을 다시 목적지로 보낸다.
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	cout << std::setprecision(9)<<pow(2,n)-1 << endl; // cout출력 자리수 제한 늘림
	Hanoi(1,3,n);
	return 0;
}

/*
하노이 문제에서 가장 큰 원판을 잠시 옆으로 빼두고 큰원판 옮겼을때 그 이후에 다시 제자리로 돌려준다는
바킹독의 힌트로 인해 쉽게 풀었다.
1. 가장 큰 원판은 제외한 원판들을 잠시 옆으로 빼둘 수 있는 코드 작성(재귀적)
2. 큰 원판을 목적지에 옮기고 다시 빼둔 원판들 목적지에 갖다 놓음(재귀적)
3. 몇번 움직였는 지에 대해서는 2^n-1번이라는 건 알았지만 바킹독에서는 그값을 쉬프트 연산을 이용해 풀었지만 나는 pow썼다..
==>근데 pow쓰니까 cout의 double형 자릿수 출력 제한 걸려서 이거 바꾸는 데, 더 힘들고 귀찮아진것 같다..
*/
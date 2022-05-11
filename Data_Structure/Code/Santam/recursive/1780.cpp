#include <iostream>

using namespace std;

int res[3] = { 0 };

int map[2187][2187] = { 0 };

int Res(int n,int p_x,int p_y)
{
	if (n == 1)
	{
		res[map[p_x][p_y]+1]++;
		return map[p_x][p_y];
	}
	else
	{
		int temp = Res(n/3,p_x,p_y);
		bool dif_num_chk = false;
		for (int i = 1;i < 9;i++)
		{
			if (temp != Res(n / 3, p_x+(i % 3) * (n / 3), p_y+(i / 3) * (n / 3))) dif_num_chk = true;
		}
		if (temp == -2) dif_num_chk = true;

		if (dif_num_chk)
		{
			return -2;
		}
		else
		{
			res[map[p_x][p_y] + 1]-=8;	
			return map[p_x][p_y];
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cin >> map[i][j];
		}
	}

	Res(n,0,0);
	cout << res[0] << "\n" << res[1] << "\n" << res[2];
	return 0;
}

/*
먼저 nxn의 행렬의 값을 담은 배열을 만들고 재귀적으로 칸 9구역을 나눠서 각 구역이 같은지 다른지 비교해서 같으면 결과값을 더하고 다르면 아무일도 없도록 해서 구현
1. Res함수에 각 구역을 나눌 수 있는 반복문과 모든 구역이 같은 지의 여부를 나타내는 dif_num_chk플래그를 만들었더,
2. 모든 구역이 같은 숫자면 재귀적으로 불러내서 결과값이 중복된 경우를 빼주고(-8씩), 어떤 값으로 모든 구역이 같은지를 반환해준다.
3. 만약 구역마다의 숫자가 다르다면, 비정상적 종료숫자 반환
4. 위의 과정을 반복하다 n이 1인경우에는 구역이 하나이므로 결과값을 더해준다.
요약: n이 k일때 구역이 모두 같을때 k+1의 9개 구역 중 한 구역이 한칸이라고 바꿔생각한다. ==> 반복 ,,또는 k일때 구역이 다른곳이 있다면 k+1의 9개 구역도 모두 같지 않음
*/
#include<iostream>
using namespace std;

int main(void)
{
	int N, v, count = 0;		//-100<= v <=100
	int arr[105] = { 0 };
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> v;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == v)
			count++;
	}
	cout << count;
	return 0;
}
/*
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // -100 <= v && v <= 100 이므로 음수도 저장할 수 있는 공간을 배열에 추가
  int N, v, a[201] = {};
  cin >> N;

  // 입력값을 배열에 저장
  while(N--){
	int t;
	cin >> t;
	// 음수도 인덱스로 접근하기 위해 기존 인덱스+100으로 배열에 저장
	a[t+100]++;
  }

  // v의 개수를 배열에서 확인
  cin >> v;
  cout << a[v+100];
}*/
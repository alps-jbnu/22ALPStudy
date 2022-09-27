#include <iostream>
#include <stack>
using namespace std;

int main(){
	int N;
	stack<int> s;					//arr[i]랑 비교할 수들을 저장하는 스택 
	int arr[1000000] = {0};			//입력된 값들을 저장하는 배열 
	int ans[1000000] = {0};			//출력할 값들을 저장하는 배열 
	cin >> N;
	
	for(int i = 0; i<N; i++){
		cin >> arr[i];
	}
	
	for(int i = N-1; i >= 0; i--){
		while(!s.empty()){			//스택에 값이 있을 때 
			if(s.top() > arr[i]){	//스택 맨 위의 값이 arr보다 크면 
				ans[i] = s.top();	//출력할 값을 저장하고 
				s.push(arr[i]);		//현재까지 중 s.top 다음으로 큰 수가 현재 값이므로 스택에 저장 
				break;				//arr[i]의 오큰수 구하기 완료 
			}
			else{					//스택 맨 위의 값이 arr[i]보다 크지 않으면 
				s.pop();			//어차피 앞쪽에 값들과 비교할 때도 쓸모 없는 값이고, 오큰수도 아니므로 스택에서 지움 
			}
			
		}
		
		if(s.empty()){				//스택에 값이 비워져 있으면 
			ans[i] = -1;			//오큰수가 존재하지 않다는 의미이므로 -1 
			s.push(arr[i]); 		//현재 수가 가장 큰 수 이므로 스택에 저장 
		}
		
	}
	
	for(int i = 0; i<N; i++){
		cout << ans[i] << ' ';
	}
}

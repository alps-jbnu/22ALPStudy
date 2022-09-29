#include <iostream>
#include <stack>

using namespace std;

int arr1[1000000];
int arr2[1000000];

int main(){
	stack<int> S;
	int N;
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> arr1[i];
	for(int i=N-1; i>=0; i--){
		while(1){
			if(S.empty()&&arr2[i]==0){
				arr2[i]=-1;
				S.push(arr1[i]);
				break;
			}
			else{
				if(arr1[i]<S.top()){
					arr2[i]=S.top();
					S.push(arr1[i]);
					break; 
				}
				else
					S.pop();
			}
		}
	}
	for(int i=0; i<N; i++)
		cout << arr2[i] <<" ";
	return 0;
}

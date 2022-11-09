#include <iostream>

using namespace std;

int arr[100000];
int arr2[2000000];
int main(){
	int n, x, cnt=0;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	cin >> x;
	for(int i=0; i<n; i++){
		if(x-arr[i]>0){
			if(arr2[x-arr[i]])
				cnt++;
			else
				arr2[arr[i]]=1;
		}
	}
	cout << cnt;
	
	return 0;
}

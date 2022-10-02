#include <iostream>
#include <string>

using namespace std;

int set[10];

int main(){
	int cnt=0, plag=0;
	string s1;
	cin >> s1;
	for(int i=0; i<s1.size(); i++){
		if(s1[i]-48==9||s1[i]-48==6){
			if(set[6])
				set[6]--;
			else if(set[9])
				set[9]--;
			else{
				for(int j=0; j<10; j++)
				set[j]++;
				cnt++;
				set[s1[i]-48]--;
			}
		}
		else if(set[s1[i]-48]>0){
			set[s1[i]-48]--;	
		}
		else if(!set[s1[i]-48]){
			for(int j=0; j<10; j++)
				set[j]++;
			cnt++;
			set[s1[i]-48]--;
		}
	}
	cout << cnt; 
	return 0;
}

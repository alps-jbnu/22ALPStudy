#include <iostream>
#include <stack>
using namespace std;

stack<long long> garden;
int num;
long long height, sum = 0;

int main(void)
{	
	cin >> num;
	for(int i = 0; i < num; i++)
	{ 
		cin >> height;
		while(!garden.empty() && garden.top() <= height) {
			garden.pop();
		}
		garden.push(height);
		sum += garden.size()-1;	
	}

	cout << sum;
}


#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<long long> garden;
int sum, num;
vector<long long> save;
long long height = 0;

int main(void)
{
	cin >> num;
	for(int i = 0; i < num; i++) {
		cin >> height;
		garden.push(height);
	}
	 
	for(int i = 0; i < num-1; i++) { 
		save.push_back(garden.top());
		garden.pop();
		if(garden.empty()) break;
		for(int j = i; j >= 0; j--) {
			if(garden.top() <= save[j]) {
				break; 
			}
			if(garden.top() > save[j]) { 
				sum++;
			}
		}
	}
	
	cout << sum;
}

 

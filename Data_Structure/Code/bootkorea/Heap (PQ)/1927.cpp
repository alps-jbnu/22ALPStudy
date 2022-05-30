#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char *argv[]) {
    int N;
    int x;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    scanf("%d", &N);
    
    while(N--)
    {
        scanf("%d", &x);
        if(x == 0)
        {
            if(pq.empty())
            {
                printf("0\n");
            }
		    else
            {
                printf("%d\n", pq.top());
				pq.pop();
            }
        }
        else
        {
            pq.push(x);
        }
    }
    
    return 0;
}
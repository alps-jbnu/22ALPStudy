#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    const int N = progresses.size();
    
    for (int i=0;i<N;)
    {
        int cnt = 0;
        const int remain = 100-progresses[i];
        int days = remain/speeds[i] + (remain%speeds[i]==0?0:1);
        for (int k=i; k<N;++k)
            progresses[k] = min(progresses[k]+speeds[k]*days, 100);
        for (int k=i; k<N; ++k)
            if (progresses[k] >= 100)
                ++cnt, ++i;
            else break;
        answer.push_back(cnt);
    }
    return answer;
}

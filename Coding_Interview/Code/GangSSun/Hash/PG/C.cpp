#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    
    for(auto v : clothes){//입력 받은 배열의 1번 인덱스가 옷의 종류
        m[v[1]] +=1;//옷의 종류를 map에 추가하고 종류의 개수 증가
    }
    for(auto iter=m.begin();iter!=m.end();iter++){
        answer *= iter->second+1;//map을 순회하며 옷 종류만큼 옷개수 + 1을 곱함
    }
    answer--;//알몸인 경우는 없으니 1 감소
    return answer;
}

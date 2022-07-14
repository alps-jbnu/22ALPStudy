#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
//터널에 들어간 차량을 Map에 저장하고
//나온 차량의 번호로 map에서 탐색하여 순서대로 벡터에 삽입
//들어간 차량의 순서와 나온 차량의 순서를 비교하여 현재 차량보다 터널에 늦게 들어갔는데 현재 차량보다 터널에서 더 일찍 나온 경우, cnt ++
int main(){
    int N,cnt=0,tmp;
    string str, test;
    unordered_map<string, int> input;
    vector<int> v;

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>str;
        input[str]=i;
    }
    for(int i=0;i<N;i++){
        cin>>str;
        v.push_back(input[str]);
    }
    for(int i=0;i<N-1;i++){
        for(int j=i;j<N;j++){
            if(v[i]>v[j]) {
                cnt++;
                break;
            }
        }
    }
    cout<<cnt<<"\n";
}
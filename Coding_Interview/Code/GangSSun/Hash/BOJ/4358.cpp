#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    map<string, double> m;
    string str;
    double sum=0;
    
    while(getline(cin, str)){
        
        sum++;
        m[str]++;//해당 종을 입력받을때 마다 갯수 ++
    }
    cout<<fixed;
    cout.precision(4);
    for(auto iter=m.begin();iter!=m.end();iter++){
        cout<<iter->first<<" "<<(iter->second/sum*100)<<endl;//map을 순회하며 해당 종의 비율을 출력
    }
    
}
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

//map에 이름, 현재 I의 값으로 저장
//단 먼저 map에 이름이 존재하는지 확인후, 존재한다면 추가하고 없다면 새로 삽입
//존재하지 않는 이름이 입력된경우 무시
//정보를 구매할 경우, 이름을 key로 하여 인덱스를 찾고, 그 해당 set으로 이동
int main(){
    map<string, long long> name;
    vector<multiset<long long>> info;//가치가 동일한 여러개의 정보가 입력될 수 있으니 multiset사용

    long long Q,menu,k,c,cnt=0,num;
    long long vidx=0,idx,info_cnt,tmp;
    string str;

    cin>>Q;
    for(long long i=0;i<Q;i++){
        cin>>menu;
        if(menu==1){
            cin>>str>>k;
            if(name.find(str)==name.end()){//존재하지 않는 경우
                name[str]=vidx;
                vidx++;//현재 벡터의 index 증가
                multiset<long long> tmp;
                for(long long j=0;j<k;j++){
                    cin>>num;
                    tmp.insert(num);//임시 set에 정보들을 삽입
                }
                info.push_back(tmp);//vector에 임시 set삽입
            }
            else{//존재하는 경우
                idx=name[str];
                for(long long j=0;j<k;j++){
                    cin>>num;
                    info[idx].insert(num);
                }
            }
        }
        else if(menu==2){
            cin>>str>>info_cnt;
            if(name.find(str)!=name.end()){//이름이 존재하는 경우
                idx=name[str];//해당 정보 고릴라의 이름을 참조하여 인덱스를 얻음
                for(auto iter=info[idx].rbegin();iter!=info[idx].rend();){//해당 set을 순회
                    tmp=*iter;
                    multiset<long long>::iterator it=info[idx].find(tmp);//동일한 정보가 다 사라지는것을 방지하기 위해 반복자 사용
                    info[idx].erase(it);//거래한 정보 set에서 삭제
                    cnt+=tmp;
                    info_cnt--;
                    if(!info_cnt) break;
                }
            }
            else continue;
        }
    }
    cout<<cnt<<"\n";
}
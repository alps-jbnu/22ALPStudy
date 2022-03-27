#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    map<string, int> m;
    
    int p_size=participant.size();
    int c_size=completion.size();
    
    for(int i=0;i<c_size;i++){
        m[completion[i]]++;
    }
    for(int i=0;i<p_size;i++){
        m[participant[i]]--;
        if(m[participant[i]]<0){
            return participant[i];
        }
    }
}

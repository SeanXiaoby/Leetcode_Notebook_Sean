#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    if(s.size()<p.size())   return res;
    int slow = 0, fast = 0;
    unordered_map<char, int> marker;
    while(fast<p.size()){
        marker[s[fast]]++;
        fast++;
    }
    fast--;
    
    while(true){
        unordered_map<char, int> temp = marker;
        bool bFlag = true;
        for(int i = 0; i<p.size(); ++i){
            if(!temp.count(p[i])){
                bFlag = false;
                break;
            }
            temp[p[i]]--;
            if(temp[p[i]] == 0) temp.erase(p[i]);
        }
        if(bFlag && temp.size() == 0){
            res.push_back(slow);
        }
        fast++;
        slow++;
        if(fast==s.size())  break;
        marker[s[fast]]++;
        marker[s[slow]]--;
        if(marker[s[slow]] == 0)    marker.erase(s[slow]);
    }
    return res;
}

int main(){
    string s = "cbaebabacd", p = "abc";
    auto res = findAnagrams(s, p);
    return 0;
}
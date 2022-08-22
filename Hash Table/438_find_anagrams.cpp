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
    unordered_map<char, int> compare;
    while(fast<p.size()){
        marker[s[fast]]++;
        compare[p[fast]]++;
        fast++;
    }
    fast--;
    
    while(true){
        unordered_map<char, int> temp = marker;
        if(marker == compare){
            res.push_back(slow);
        }
        fast++;
        if(fast==s.size())  break;
        marker[s[fast]]++;
        marker[s[slow]]--;
        if(marker[s[slow]] == 0)    marker.erase(s[slow]);
        slow++;
    }
    return res;
}

int main(){
    string s = "cbaebabacd", p = "abc";
    auto res = findAnagrams(s, p);
    return 0;
}
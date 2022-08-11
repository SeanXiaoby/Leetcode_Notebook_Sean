#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#include<unordered_set>

using namespace std;

// bool IsHaveRepeat(unordered_map<char, int> mark){
//     for(auto iter = mark.begin(); iter!= mark.end(); iter++){
//         if(iter->second >1) return true;
//     }
//     return false;
// }

int lengthOfLongestSubstring(string s) {
    unordered_set<char> mark;
    int res = INT_MIN;
    
    for(int i = 0, j = 0; j<s.size(); ++j){
        while(mark.count(s[j])){
            mark.erase(s[i]);
            i++;
        }
        mark.insert(s[j]);
        res = (j-i+1) >= res ? (j-i+1) : res;
    }
    
    return res == INT_MIN ? 0 : res;
}

int main(){
    string test = "abcabcbb";
    cout<<lengthOfLongestSubstring(test)<<endl;
    return 0;
}
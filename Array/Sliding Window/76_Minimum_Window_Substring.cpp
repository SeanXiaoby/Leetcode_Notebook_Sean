#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Solution 1 : Exceeded time limits

// bool isStringMatched(unordered_map<char, int> input, unordered_map<char, int> require){
//     for(auto iter = input.begin(); iter!= input.end(); iter++){
//         if(iter->second < require[iter->first]){
//             return false;
//         }
//     }
//     return true;
// }


// string minWindow(string s, string t) {
//     int slow = 0, minSize = INT_MAX;
//     string res;
//     unordered_map<char, int> target, require, other;

//     for(auto iter = t.begin(); iter!=t.end(); iter++){
//         require[*iter] ++;
//         target[*iter]  = 0;
//     }

//     for(int j = 0; j<s.size(); ++j){

//         if(target.count(s[j]) != 0){
//             target[s[j]]++;
//             while(isStringMatched(target, require)){
//                 if((j-slow+1)<= minSize){
//                     minSize = j-slow+1;
//                     res = s.substr(slow, minSize);
//                 }
//                 if(target.count(s[slow]) != 0){
//                     target[s[slow]]--;
//                 }
//                 slow++;
//             }
//         }

//     }

//     return res;
// }


string minWindow(string s, string t) {
    int slow = 0, minSize = INT_MAX, cnt = 0;
    string res;
    unordered_map<char, int> target, require;

    for(auto iter = t.begin(); iter!=t.end(); iter++){
        require[*iter] ++;
        // target[*iter]  = 0;
    }

    for(int j = 0; j<s.size(); ++j){
        target[s[j]]++;
        if(target[s[j]]<=require[s[j]]) cnt++;
        while(target[s[slow]] > require[s[slow]]){
            target[s[slow]]--;
            slow++;
        }

        if(cnt == t.size()){
            if((j-slow+1)<= minSize){
                minSize = j-slow+1;
                res = s.substr(slow, minSize);
            }
        }
        
    }

    return res;
}


int main(){
    string input =  "ADOBECODEBANC";
    string target = "ABC";

    cout<<minWindow(input, target)<<endl;

    return 0;
}
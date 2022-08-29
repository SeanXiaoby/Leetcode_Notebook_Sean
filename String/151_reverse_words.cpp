#include<string>
#include<iostream>
#include<vector>

using namespace std;

string reverseWords(string s) {
    vector<string> words;
    string res;
    int slow = -1, fast = 0;
    while(fast < s.size()){
        if(fast == 0){
            if(s[fast] != ' '){
                slow = fast;
            }
        }else if(s[fast] != ' ' && s[fast-1] == ' '){
            slow = fast;
        }
        if(fast == s.size()-1){
            if(s[fast]!=' '){
                if(slow != -1){
                    words.push_back(s.substr(slow, fast-slow+1));
                }
            }
            break;
        }else if(s[fast] != ' ' && s[fast+1] == ' '){
            if(slow != -1){
                    words.push_back(s.substr(slow, fast-slow+1));
                }
        }
        fast++;
    }
    for(int i = words.size()-1; i>=0; --i){
        res += words[i];
        if(i != 0){
            res += " ";
        }
    }
    return res;
}

int main(){

    string input = "the sky is blue";
    auto res = reverseWords(input);
    return 0;

}
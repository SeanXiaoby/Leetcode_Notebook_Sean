#include<string>
#include<iostream>
#include<vector>

using namespace std;

string reverseWords(string s) {
    vector<string> words;
    string res;
    int slow = 0, fast = 1;
    while(fast < s.size()){
        if(s[fast] != ' ' && s[fast-1] == ' '){
            slow = fast;
            cout<<slow<<endl;
        }
        if(fast = s.size()-1){
            if(s[fast]!=' '){
                words.push_back(s.substr(slow, fast-slow+1));
            }
            break;
        }else if(s[fast] != ' ' && s[fast+1] == ' '){
            words.push_back(s.substr(slow, fast-slow+1));
            cout<<fast<<endl;
        }
        fast++;
    }
    for(auto iter = words.begin(); iter!= words.end(); iter++){
        cout<<*iter<<"--";
    }
    return res;
}

int main(){

    string input = "the sky is blue";
    auto res = reverseWords(input);
    return 0;

}
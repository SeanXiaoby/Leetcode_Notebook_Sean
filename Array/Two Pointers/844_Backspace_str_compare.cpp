#include<iostream>
#include<string>
#include<vector>

using namespace std;

string RemoveHash(string input){
    if(input.empty())   return input;
    int slow = 0;
    for(int i = 0; i<input.size(); ++i){
        if(input[i] != '#'){
            input[slow] = input[i];
            slow++;
        }else{
            slow--;
            if(slow<0)  slow = 0;
        }
    }

    return input.substr(0, slow);
}


bool backspaceCompare(string s, string t) {
    s = RemoveHash(s);
    t = RemoveHash(t);
    
    return (s == t);
}


int main(){
    string str1 = "abcd#e", str2 = "abce";
    cout<<backspaceCompare(str1, str2)<<endl;
    return 0;
}
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void bfsHelper(vector<string> &res, string curStr, vector<int> digits, int curDigit, vector<vector<char> > keys){
    if(digits.empty())  return;

    if(curDigit == digits.size()){
        res.push_back(curStr);
        return;
    }

    auto key = keys[digits[curDigit]];

    for(auto iter = key.begin(); iter!= key.end(); iter++){
        bfsHelper(res, curStr+*iter, digits, curDigit+1, keys);
    }
}


vector<string> letterCombinations(string digits) {
    vector<vector<char> > keys = {
        {},{},
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'}
    };
    
    vector<int> vDigits;
    for(auto iter = digits.begin(); iter!= digits.end(); iter++){
        vDigits.push_back(*iter - '0');
    }

    vector<string> res;
    string curStr = "";

    bfsHelper(res, curStr, vDigits, 0, keys);

    return res;

}

int main(){
    string input = "232";

    auto res = letterCombinations(input);

    return 0;
}
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;


bool isHalfValid(string s){
    stack<char> memo;
    for(auto iter = s.begin(); iter!= s.end(); iter++){
        if(*iter == '('){
            memo.push(*iter);
        }else{
            if(memo.empty()){
                return false;
            }else{
                memo.pop();
            }
        }
    }
    return true;
}

bool isValid(string s){
    stack<char> memo;
    for(auto iter = s.begin(); iter!= s.end(); iter++){
        if(*iter == '('){
            memo.push(*iter);
        }else{
            if(memo.empty()){
                return false;
            }else{
                memo.pop();
            }
        }
    }
    return memo.empty()?true:false;
}

void dfsHelper(int n, vector<string> &res, string curStr, vector<int> counter){
    if(curStr.size()==n*2){
        // if(isValid(curStr)) res.push_back(curStr);
        res.push_back(curStr);
        return;
    }

    //if(!isHalfValid(curStr))    return;

    if(counter[0] < n){
        auto nextCounter = counter;
        nextCounter[0]++;
        dfsHelper(n, res, curStr+'(', nextCounter);
    }

    if(counter[0]>counter[1]){
        auto nextCounter = counter;
        nextCounter[1]++;
        dfsHelper(n, res, curStr+')', nextCounter);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string curStr = "";
    vector<int> counter(2,0);
    dfsHelper(n, res, curStr, counter);

    return res;
}


int main (){
    auto res = generateParenthesis(3);
    return 0;
}
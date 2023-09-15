#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;


string to_string_min(int min){
    if(min < 10){
        return ('0' + to_string(min));
    }else{
        return (to_string(min));
    }
}

bool isValid(vector<int> cur){
    if(cur[0] <= 11 && cur[1] <= 59){
        return true;
    }
    return false;
}

void bfsHelper(int turnedOn, vector<string> &res, vector<int> cur, int curLight, vector<pair<int, int> > bits){
    if(turnedOn == 0)   return;

    if(curLight > turnedOn){
        if(isValid(cur))    res.push_back(to_string(cur[0])+":"+to_string_min(cur[1]));
        return;
    }

    if(!isValid(cur))   return;

    // for(auto iter = bits.begin(); iter!= bits.end(); iter++){
    //     auto next = cur;
    //     next[iter->second] += iter->first;
    //     bfsHelper(turnedOn, res, next, curLight+1, bits);
    // }
    for(int i = 0; i<bits.size(); i++){
        auto next = cur;
        next[bits[i].second] += bits[i].first;
        auto nextBits = bits;
        nextBits.erase(nextBits.begin() + i);
        bfsHelper(turnedOn, res, next, curLight+1, nextBits);
    }
}

vector<string> readBinaryWatch(int turnedOn) {
    vector<pair<int, int> > bits = {
        {1,0},{2,0},{4,0},{8,0},
        {1,1},{2,1},{4,1},{8,1},{16,1},{32,1}
    };

    vector<string> res;
    vector<int> cur = {0,0};

    bfsHelper(turnedOn, res, cur, 1, bits);

    return res;
}

int main(){
    auto res = readBinaryWatch(5);
    return 0;
}
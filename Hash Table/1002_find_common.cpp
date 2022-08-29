#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> commonChars(vector<string>& words) {
    vector< vector<int> > counters(words.size(), vector<int>(26, 0));
    vector<string> res;
    if(words.size() == 0)   return res;
    for(int i = 0; i<words.size();++i){
        for(int j = 0; j< words[i].size();++j){
            counters[i][words[i][j]-97]++;
        }
    }
    vector<int> MinCount(26, INT_MAX);
    for(int m = 0; m<26; m++){
        for(int n = 0; n< words.size(); ++n){
            if(counters[n][m]<=MinCount[m]){
                MinCount[m] = counters[n][m];
            }
        }
        if(MinCount[m]>0){
            for(int k = 0; k<MinCount[m]; ++k){
                res.push_back(string(1, char(97+m)));
            }
        }
    }
    return res;
}

int main(){

    return 0;
}
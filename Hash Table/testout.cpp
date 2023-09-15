#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


long long solution(vector<string> queryType, vector<vector<int>> query) {
    unordered_map<int, int> data;
    long long res = 0;
    for(int i = 0; i<queryType.size(); ++i){
        auto currData = query[i];
        auto currQuery = queryType[i];
        
        if(currQuery == "insert"){
            data[currData[0]] = currData[1];
        }else if(currQuery == "get"){
            if(data.count(currData[0])){
                res += data[currData[0]];
            }
        }else if(currQuery == "addToValue"){
            for(auto iter = data.begin(); iter!= data.end(); iter++){
                iter->second += currData[0];
            }
        }else if(currQuery == "addToKey"){
            unordered_map<int, int> temp;
            for(auto iter = data.begin(); iter!= data.end(); iter++){
                temp[iter->first + currData[0]] = iter->second;
            }
            data = temp;
        }
    }
    
    return res;
}

int main(){
    vector<string> queryType = {"insert", 
                                "insert", 
                                "addToValue", 
                                "addToKey", 
                                "get"};
    vector<vector<int>> query = {
        {1,2}, {2,3}, {2}, {1}, {3}
    };

    cout<<solution(queryType, query)<<endl;

    return 0;
}
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

int totalFruit(vector<int>& fruits) {
    // // O(nlogn): Exceed time limit
    // if(fruits.size()<= 1)   return fruits.size();

    // int res = INT_MIN, start = 0;

    // for(int i = 0; i<fruits.size()-1; ++i){
    //     bool flag = false;
    //     map<int, bool> fruitType;
    //     fruitType[fruits[i]] = true;
    //     for(int j = i; j<fruits.size(); ++j){
    //         if(!fruitType[fruits[j]] && !flag){
    //             fruitType[fruits[j]] = true;
    //             flag = true;
                
    //         }else if(!fruitType[fruits[j]] && flag){
    //             break;
    //         }
    //         res = (j-i+1)>= res? (j-i+1):res;
    //     }
        
    // }
    // return res == INT_MIN ? 0 : res;


    // Try Sliding window
    if(fruits.size()<= 1)   return fruits.size();

    int res = INT_MIN, start = 0;
    map<int, int> counter;

    for(int j = 0; j<fruits.size(); j++){
        counter[fruits[j]]++;
        if(counter.size() <=2){
            res = (j-start+1) >= res? (j-start+1):res;
            continue;
        }
        while(counter.size() > 2){
            counter[fruits[start]] --;
            if(counter[fruits[start]] == 0){
                counter.erase(fruits[start]);
            }
            start++;
        }
        res = (j-start+1) >= res? (j-start+1):res;
    }

    return res;
}


int main(){
    vector<int> test = {3,3,3,1,2,1,1,2,3,3,4};
    cout<<totalFruit(test)<<endl;
    
    return 0;
}
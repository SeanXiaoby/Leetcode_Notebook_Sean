#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


void Helper(vector<vector<int>> &res, unordered_map<int, vector<vector<int>> > &memo, vector<int> curr, vector<int> nums, int size){
    if(curr.size() == size){
        res.push_back(curr);
        return;
    }

    for(int i = 0; i<nums.size(); ++i){
        curr.push_back(nums[i]);
        auto temp_nums = nums;
        temp_nums.erase(temp_nums.begin() + i);
        if(memo.count(curr.size()) == 0){
            memo[curr.size()] = {curr};
            Helper(res, memo, curr, temp_nums, size);
        }else{
            auto iter = memo[curr.size()].begin();
            for(; iter!=memo[curr.size()].end(); iter++){
                if(*iter == curr)   break;
            }

            if(iter == memo[curr.size()].end()){
                memo[curr.size()].push_back(curr);
                Helper(res, memo, curr, temp_nums, size);
            }
        }

        curr.pop_back();
    }
}


vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    unordered_map<int, vector<vector<int>> > memo;
    vector<int> curr = {};
    Helper(res, memo, curr, nums, nums.size());
    return res;
}

int main(){
    vector<int> nums = {1,1,2};
    auto res = permuteUnique(nums);

    return 0;
}
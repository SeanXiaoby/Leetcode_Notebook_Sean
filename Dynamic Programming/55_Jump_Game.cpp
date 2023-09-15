#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;


void JumpHelper(vector<int>& nums, int start, bool &bFlag, unordered_map<int, bool>& memo){
    if(start == nums.size()-1 || bFlag){
        bFlag = true;
        memo[start] = true;
        return;
    }
    
    if(start >= nums.size() || nums[start] == 0){
        memo[start] = false;
        return;
    }
    
    if(memo.count(start)){
        bFlag = memo[start];
        return;
    }
    
    for(int i = nums[start]; i>=1 ; --i){
        JumpHelper(nums, start+i, bFlag ,memo);
        memo[start+i] = bFlag;
    }
}

bool canJump(vector<int>& nums) {
    bool bFlag = false;
    unordered_map<int, bool> memo;
    JumpHelper(nums, 0, bFlag, memo);
    return bFlag;
}

int main(){
    //vector<int> input = {2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
    vector<int> input = {};
    cout<<canJump(input)<<endl;
    return 0;
}
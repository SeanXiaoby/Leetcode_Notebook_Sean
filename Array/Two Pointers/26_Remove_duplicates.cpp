#include<iostream>
#include<string>
#include<vector>

using namespace std;


int removeDuplicates(vector<int>& nums) {
    if(nums.empty())    return 0;

    int slowIndex = 1, curVal = nums[0];

    for(int fastIndex = 1; fastIndex < nums.size(); ++fastIndex){
        if(nums[fastIndex] != curVal){
            curVal = nums[fastIndex];
            nums[slowIndex] = curVal;
            slowIndex++;
        }
    }

    return slowIndex;
}
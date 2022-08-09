#include<iostream>
#include<string>
#include<vector>

using namespace std;


int lengthOfLIS(vector<int>& nums) {
    if(nums.size() <= 1) return nums.size();

    int slow = 1;
    
    for(int i = 1; i<nums.size(); i++){
        // if(nums[i]<curSmall){
        //     slow = 0;
        //     curSmall = nums[i];
        //     nums[slow] = nums[i];
        //     slow++;
        // }else if(nums[i]>nums[slow-1]){
        //     nums[slow] = nums[i];
        //     slow++;
        // }

        // int m = slow-1;
        // while(m >= 0){
        //     if(nums[i]<)
        // }
        if(nums[i]< nums[0]){
            nums[0] = nums[i];
            slow = 1;
        }else if(nums[i]>=nums[slow -1]){
            nums[slow] = nums[i];
            slow++;
        }else{
            for(int m = 1; m<slow; m++){
                if(nums[i]>nums[m-1] && nums[i]<nums[m]){
                    nums[m] = nums[i];
                    slow = m;
                }
            }
        }
    }
    
    return slow;
    
}

int main(){
    vector<int> input = {0,1,0,3,2,3};
    cout<<lengthOfLIS(input)<<endl;
}
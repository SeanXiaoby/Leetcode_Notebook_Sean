#include<iostream>
#include<string>
#include<vector>

using namespace std;

// int removeElement(vector<int>& nums, int val) {
//     for(auto iter = nums.begin(); iter!= nums.end(); ){
//         if(*iter == val){
//             iter = nums.erase(iter);
//         }else{
//             iter++;
//         }
//     }
//     return nums.size();
// }

int removeElement(vector<int>& nums, int val) {
    int slowIndex = 0;

    for(int fastIndex = 0; fastIndex < nums.size(); ++fastIndex){
        if(nums[fastIndex] != val){
            nums[slowIndex] = nums[fastIndex];
            slowIndex++;
        }
    }

    return slowIndex;
}
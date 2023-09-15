#include <iostream>
#include <vector>

using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    // Binary search

    int start = 0, end = nums.size() - 1, mid1 = -1, mid2 = -1;

    while(start <= end){
        mid1 = (start + end) /2;
        mid2 = mid1 + 1;
        if(mid2 > end){
            return nums[mid1];
        }
        
        if(nums[mid1] == nums[mid2]){
            if((mid1 - start + 1)%2 == 0){
                end = mid1 - 1;
            }else{
                start = mid2 + 1;
            }
        }else{
            if((mid1 - start + 1)%2 != 0){
                end = mid1;
            }else{
                start = mid2;
            }
        }
    }

    return -1;
}

int main(){
    vector<int> test = {1,1,2,3,3,4,4,8,8};

    cout<<singleNonDuplicate(test)<<endl;

    return 0;
}
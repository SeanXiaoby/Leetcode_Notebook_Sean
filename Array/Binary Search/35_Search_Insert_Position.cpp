#include<iostream>
#include<string>
#include<vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int res = -1;

    int left = 0, right = nums.size()-1;
    int mid = left+ (right - left)/2;

    while(true){
        if(left<right){
            if(nums[mid] == target){
                res = mid;
                break;
            }else if(nums[mid]<target){
                left = mid + 1;
            }else{
                right = mid;
            }
        }else if(left >= right){
            if(nums[mid] == target){
                res = mid;
                break;
            }else if(nums[mid]<target){
                res = mid +1;
                break;
            }else{
                res = mid;
                break;
            }
        }

        mid = left+ (right - left)/2;
    }


    return res;
}


int main(){
    vector<int> test = {-3, 0, 1, 3,9, 10};
    cout<<searchInsert(test, 2)<<endl;
    return 0;
}

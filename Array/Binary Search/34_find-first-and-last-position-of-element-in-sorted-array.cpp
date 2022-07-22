#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res = {-1, -1};

    if(nums.size() == 0){
        return res;
    }

    int left = 0, right = nums.size()-1;
    int mid = left+ (right - left)/2;

    // First binary search ==> find the starting pos
    while(left <= right){
        if(nums[mid] == target){
            if(mid == 0){
                res[0] = mid;
                break;
            }else if(nums[mid -1] < target){
                res[0] = mid;
                break;
            }else{
                right = mid -1;
            }
        }else if(nums[mid] < target){
            left = mid +1;
        }else{
            right = mid -1;
        }

        mid = left + (right - left)/2;
    }

    left = 0;
    right = nums.size()-1;
    mid = left+ (right - left)/2;
    //Second binary search ==> find the ending pos
    while(left <= right){
        if(nums[mid] == target){
            if(mid == (nums.size() - 1)){
                res[1] = mid;
                break;
            }else if(nums[mid +1] > target){
                res[1] = mid;
                break;
            }else{
                left = mid + 1;
            }
        }else if(nums[mid] < target){
            left = mid +1;
        }else{
            right = mid -1;
        }

        mid = left + (right - left)/2;
    }

    return res;
}   

int main(){
    vector<int> test = {5,7,7,8,8,10};
    vector<int> res = searchRange(test, 8);

    cout<<"{"<<res[0]<<", "<<res[1]<<"}"<<endl;
    return 0;
}
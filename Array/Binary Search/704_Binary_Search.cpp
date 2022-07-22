#include<iostream>
#include<string>
#include<vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int res = -1;

    int left = 0, right = nums.size()-1;
    int mid = left+ (right - left)/2;

    while(left<= right){
        if(nums[mid] == target){
            res = mid;
            break;
        }else if(nums[mid]<target){
            left = mid+1;
        }else{
            right = mid -1;
        }
        mid = left+ (right - left)/2;
    }


    return res;
}


int main(){
    vector<int> test = {-3, 0, 1, 3,9, 10};
    cout<<search(test, 9)<<endl;
    return 0;
}


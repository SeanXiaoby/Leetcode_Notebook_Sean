#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    // O(nlogn) solution: Exceeded time limits

    // int minSize = INT_MAX;
    
    // for(int m = 0; m<nums.size(); m++){
    //     vector<int> temp;
    //     int sum = 0;
    //     bool bFlag = false;
    //     for(int n = m; n < nums.size(); ++n){
    //         sum += nums[n];
    //         temp.push_back(nums[n]);
    //         if(sum >= target){
    //             if(temp.size()<= minSize){
    //                 minSize = temp.size();
    //             }
    //             break;
    //         }
    //     }
    // }

    // return minSize == INT_MAX ? 0 : minSize;

    // O(n): Sliding Window solution
    int res = INT_MAX, sums = 0, start = 0;
    for(int i = 0; i<nums.size(); ++i){
        sums += nums[i];
        while(sums >= target){
            res = (i-start+1)<= res ? (i-start+1):res;
            sums -= nums[start];
            start++;
        }
    }
    return res == INT_MAX ? 0 : res;
}


int main(){
    vector<int> test = {2,5,7,9};
    cout<<minSubArrayLen(20, test)<<endl;
    return 0;
}
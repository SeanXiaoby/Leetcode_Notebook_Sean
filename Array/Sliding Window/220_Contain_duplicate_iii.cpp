#include<iostream>
#include<vector>
#include<unordered_set>
#include<math.h>
#include<set>

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if(!k || nums.size()<=1)  return false;
    set<int> counter;
    for(int i = 0, j = 0; j< nums.size(); ++j){
        while(abs(i-j)> k){
            counter.erase(nums[i]);
            i++;
        }
        
        if(!counter.empty()){
            // auto iter = counter.begin();
            // int start = *iter;
            // iter = counter.end();
            // iter--;
            // int end = *iter;
            // if(nums[j]>= start-t && nums[j]<= end +t){
            //     return true;
            // }
            for(auto iter = counter.begin(); iter!= counter.end(); iter++){
                // double = 
                if(abs(nums[j] - *iter)<= t) return true;
            }
        }
        counter.insert(nums[j]);

    }

    return false;
}

int main(){
    vector<int> input = {-2147483648,2147483647};
    cout<<containsNearbyAlmostDuplicate(input, 1,1)<<endl;
    return 0;
}

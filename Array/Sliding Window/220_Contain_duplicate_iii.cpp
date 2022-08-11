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
            for(auto iter = counter.begin(); iter!= counter.end(); iter++){
                double left = abs
                if(abs((double)nums[j] - (double)*iter)<= (double)t) return true;
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

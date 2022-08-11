#include<iostream>
#include<vector>
#include<unordered_set>
#include<math.h>
#include<set>

using namespace std;


bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> counter;
    for(int i = 0, j = 0; j< nums.size(); ++j){
        while(abs(i-j)> k){
            counter.erase(nums[i]);
            i++;
        }
        if(counter.count(nums[j]))  return true;
        counter.insert(nums[j]);
        
    }
    
    return false;
}



int main(){
    vector<int> input = {1,2,3,1,2,3};
    cout<<containsNearbyDuplicate(input, 2)<<endl;

    // set<int> test;
    // test.insert(10);
    // test.insert(1);
    // test.insert(5);
    // auto iter1 = test.begin(), iter2 = test.end();
    // iter2--;
    // cout<<*iter1<<"  "<<*iter2<<endl;

    return 0;
}
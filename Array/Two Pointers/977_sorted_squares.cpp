#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> res;
    if(nums.empty()) return res;
    int ptr1 = 0, ptr2 = nums.size()-1;
    while(ptr1 != ptr2){
        if(pow(nums[ptr1],2)>= pow(nums[ptr2],2)){
            res.push_back(pow(nums[ptr1],2));
            ptr1++;
        }else{
            res.push_back(pow(nums[ptr2],2));
            ptr2--;
        }
    }

    res.push_back(pow(nums[ptr1],2));
    reverse(res.begin(), res.end());
    return res;
}


int main(){
    vector<int> vec = {-2, -1, 0 , -1, 4};
    auto res = sortedSquares(vec);

    for(auto iter = res.begin(); iter!=res.end(); iter++){
        cout<<*iter<<endl;
    }
    return 0;
}
#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> counter1(1001,0), counter2(1000,0);
    vector<int> res;
    for(int i = 0; i< nums1.size(); ++i){
        counter1[nums1[i]]++;
    }
    for(int i = 0; i< nums2.size(); ++i){
        counter2[nums2[i]]++;
    }
    for(int i = 0; i< 1001; ++i){
        int minVal = min(counter1[i], counter2[i]);
        for(int j = 0; j<minVal; ++j){
            res.push_back(i);
        }
    }
    return res;
}

int main(){
    
    return 0;
}
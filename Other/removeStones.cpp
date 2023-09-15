#include<vector>
#include<iostream>

using namespace std;

int removeStones(vector<vector<int>>& stones) {
    int res = 0;
    auto slow = 0;

    while(slow<stones.size()){
        auto cur = stones[slow];
        auto fast = stones.begin()+slow+1;
        while(fast != stones.end()){
            auto cur_back = *fast;
            if(cur[0] == cur_back[0] || cur[1] == cur_back[1]){
                fast = stones.erase(fast);
                res++;
            }else{
                fast++;
            }
        }
        slow++;
    }
    return res;
}


int main(){
    vector<vector<int> > stones = {{0,0}, {0,1}, {1,0}, {2,1}, {1,2}, {2,2}};
    cout<<removeStones(stones)<<endl;
    return 0;
}
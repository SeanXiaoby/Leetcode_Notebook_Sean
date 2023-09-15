#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


// void FindHelper(vector<int> coins, int amount, int cur, vector<vector<int> > & memo){
//     if(cur >= coins.size() || amount <=0){
//         return;
//     }
    
//     if(coins[cur] > amount){

//     }else{

        
//     }
    
// }

// int coinChange1(vector<int>& coins, int amount) {
//     vector<vector<int> > memo(coins.size()+1, vector<int>(amount +1, INT_MAX-1));

//     for(int i = 0; i < )

//     int res = FindHelper(coins, amount, 0, memo);
//     return res;
// }

int coinChange1(vector<int>& coins, int amount) {
    vector<int> dp (amount+1, INT_MAX -1);
    dp[0] = 0;
    
    for(auto c : coins){
        for(int a = c; a<=amount; ++a){
            dp[a] = min(dp[a], dp[a-c]+1);
        }
    }

    return dp[amount] == INT_MAX -1? -1:dp[amount];
}

int coinChange2(vector<int>& coins, int amount) {
    vector<int> dp (amount+1, INT_MAX -1);
    dp[0] = 0;
    for(int curAmount = 1; curAmount <= amount; ++curAmount){
        for(int i = 0; i < coins.size(); ++i){
            if(coins[i] <= curAmount){
                dp[curAmount] = min(dp[curAmount- coins[i]]+1, dp[curAmount]);
            }
        }
    }

    return dp[amount] == INT_MAX -1? -1:dp[amount];
}

int main(){
    // vector<int> coins = {1,2,5};
    // int amount = 11;

    // cout<<coinChange1(coins, amount)<<endl;

    int a  = 10, b = 200;
    cout<<(a ^ b)+(a & b)*2<<endl;
    return 0;
}
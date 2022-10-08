#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


bool hasApple(vector<vector<int> > appleCount, int x1, int y1, int x2, int y2){
    return (appleCount[x2][y2] - appleCount[x2][y1] - appleCount[x1][y2] + appleCount[x1][y1])>0? true:false;
}

int countApple(vector<vector<int> > appleCount, int x1, int y1, int x2, int y2){
    return (appleCount[x2][y2] - appleCount[x2][y1] - appleCount[x1][y2] + appleCount[x1][y1]);
}

int ways(vector<string>& pizza, int k){
    int kMod = 1e9+7;
    int M = pizza.size(), N = pizza[0].size();
    vector<vector<int> > appleCount(M+1, vector<int>(N+1, 0));
    
    for(int m = 0; m<M; m++){
        for(int n = 0; n<N; n++){
            appleCount[m+1][n+1] = appleCount[m][n+1] + appleCount[m+1][n]+ (pizza[m][n] == 'A') - appleCount[m][n];
        }
    }

    vector<vector<vector<int> > > memo (M+1, vector<vector<int> >(N+1, vector<int>(k+1, -1)));

    for(int m = M-1; m >=0 ; --m){
        for(int n = N-1; n>= 0; --n){
            memo[m][n][1] = countApple(appleCount, m, n, M, N) > 0;
            for(int t = 2; t<= k; ++t){
                
                for(int i = m + 1; i < M; ++i){
                    if(countApple(appleCount, m, n, M, N) == countApple(appleCount, i, n, M ,N))    continue;
                    if(countApple(appleCount, i, n, M ,N) == 0)   break;
                    
                    memo[m][n][t] = (memo[m][n][t] + memo[i][n][t-1]) ;
                }
                
                for(int j = n+1; j < N; ++j){
                    if(countApple(appleCount, m, n, M, N) == countApple(appleCount, m, j, M, N))    continue;
                    if(countApple(appleCount, m, j, M, N) == 0)   break;

                    memo[m][n][t] = (memo[m][n][t] + memo[m][j][t-1]) ;
                }
            }
        }
    }

    return memo[0][0][k];

}



int main(){
    vector<string> input = {"A..","AAA","..."};
    cout<< ways(input, 3)<<endl;

    return 0;
}


/*
A . .
A A A
. . .

*/
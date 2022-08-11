#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int loop = 0, num = 1;

    while(loop < n/2){
        for(int i = 0+loop; i<n-loop-1; i++){
            res[loop][i] = num++;
        }

        for(int i = 0+loop; i<n-loop-1; i++){
            res[i][n-1-loop] = num++;
        }

        for(int i = n-loop-1; i > loop; i--){
            res[n-loop-1][i] = num++;
        }

        for(int i = n-loop-1; i > loop; i--){
            res[i][loop] = num++;
        }

        loop++;
    }
    if(n&1){
        res[loop][loop] = num;
    }

    return res;
}



int main(){
    int n = 9;

    auto res = generateMatrix(n);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j<n; ++j){
            cout<<res[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
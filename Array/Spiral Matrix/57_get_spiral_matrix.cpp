#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if(matrix.empty())  return res;
    int loop = 0, n = matrix.size(), m = matrix[0].size();

    while(res.size() < n*m && loop < max(n/2, m/2)){
        for(int i = loop; i < m-loop-1 && res.size() < n*m; i++){
            res.push_back(matrix[loop][i]);
        };
        for(int i = loop; i < n-loop-1 && res.size() < n*m; i++){
            res.push_back(matrix[i][m-loop-1]);
        }
        for(int i = m-loop-1; i > loop && res.size() < n*m; i--){
            res.push_back(matrix[n-loop-1][i]);
        }
        for(int i = n-loop-1; i > loop && res.size() < n*m; i--){
            res.push_back(matrix[i][loop]);
        }

        loop++;
    }

    if(m == n && m&1){
        res.push_back(matrix[loop][loop]);
    }

    return res;
}



int main(){
    vector<vector<int>> matrix = { {6,9,7,5},{6,9,7,5},{6,9,7,5}};

    auto res = spiralOrder(matrix);

    for(auto iter = res.begin(); iter!= res.end(); iter++){
        cout<<*iter<<" ";;
    }
    cout<<endl;
    return 0;
}
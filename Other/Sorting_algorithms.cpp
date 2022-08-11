// Example program
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> CountingSort(vector<int> input){
    vector<int> counts(1000);
    for(auto iter = input.begin(); iter!= input.end();iter++){
        counts[*iter]++;
    }
    
    vector<int> res;
    
    for(int i = 0; i<counts.size(); ++i){
        for(int m = 0; m<counts[i]; ++m){
            res.push_back(i);   
        }
    }
    
    return res;
}

void SelectionSort(vector<int> &input){

    int nStart = 0, nMin = INT_MAX, nMinIndex = 0;

    while(nStart< input.size()){

        // Heap can be used here to find the minimum
        for(int i = nStart; i<input.size(); ++i){
            if(input[i]<= nMin){
                nMin = input[i];
                nMinIndex = i;
            }
        }
        int temp = input[nStart];
        input[nStart] = input[nMinIndex];
        input[nMinIndex] = temp;

        nMin = INT_MAX;
        nMinIndex = nStart;

        nStart++;
    }
}

void BubbleSort(vector<int> &input){
    bool nChanged = false;

    do{
        nChanged = false;

        for(int i = 0; i < input.size() -1; ++i){
            if(input[i]>input[i+1]){
                auto temp = input[i];
                input[i] = input[i+1];
                input[i+1] = temp;
                nChanged = true;
            }
        }

    }while(nChanged);
}


void MergeSort(vector<int> input){

}

void MergeTwoVector(vector<int> input, int l, int r, vector<int> res){
    
}




void PrintVector(vector<int> input){
    cout<<"{";
    for(auto iter = input.begin(); iter!=input.end(); iter++){
        cout<<*iter<<", ";
    }
    cout<<"}"<<endl;
}

int main()
{
    vector<int> test; 
    for(int i = 0; i<50; ++i){
      test.push_back(rand() % (100 - 1) +1);
    }
    PrintVector(test);
    BubbleSort(test);
    PrintVector(test);
    return 0;
}

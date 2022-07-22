#include<iostream>
#include<vector>

using namespace std;

int mySqrt(int x) {
    if(x<1){
        return 0;
    }

    int left = 1, right = x;
    int mid = left + (right - left) /2;

    while(left <= right){
        if(mid*mid == x){
            return mid;
        }else if(mid == 1 || mid == x){
            return mid;
        }else if(mid*mid < x && x < (mid+1)*(mid+1)){
            return mid;
        }else if((mid-1)*(mid-1) < x && x < mid*mid){
            return (mid -1);
        }else if(x < mid*mid){
            right = mid -1;
        }else if(x > mid*mid){
            left = mid +1;
        }

        mid = left + (right - left) /2;
    }

    return 0;
}


int main(){
    int x = 24;
    cout<<mySqrt(x)<<endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3) return false;
        int left=0,right=A.size()-1;
        while(left<A.size()-1&&A[left]<A[left+1]){
            left++;
        }
        while(right>0&&A[right]<A[right-1]){
            right--;
        }
        if(left==right&&left>0&&right<A.size()-1) return true;
        else return false;
    }
};

int main(){
    vector<int> A={0,1,2,3,4,5,6,7,8,9};
    Solution ans;
    cout<<ans.validMountainArray(A);
}
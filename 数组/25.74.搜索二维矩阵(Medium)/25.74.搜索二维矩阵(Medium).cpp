#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {//双指针缩短搜索空间
//        if(matrix.empty()) return false;
//        int rows=matrix.size();
//        int cols=matrix[0].size();
//        if(rows>0&&cols>0){
//            int l=0,r=cols-1;
//            while(l<rows && r>=0){
//                if(matrix[l][r]<target) l++;
//                else if(matrix[l][r]>target) r--;
//                else return true;
//            }
//        }
//        return false;
//    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {//二分法
        if(matrix.empty()) return false;
        int l=0,r=matrix.size()*matrix[0].size()-1;
        int n=matrix[0].size();
        while(l<=r){
            int mid=(l+r)/2;
            int row=mid/n;
            int col=mid%n;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
};

int main(){
    vector<vector<int>> matrix;
    vector<int> nums1={1,3,5,7};
    vector<int> nums2={10,11,16,20};
    vector<int> nums3={23,30,34,50};
    matrix.push_back(nums1);matrix.push_back(nums2);matrix.push_back(nums3);
    Solution ans;
    cout<<ans.searchMatrix(matrix,3);
}
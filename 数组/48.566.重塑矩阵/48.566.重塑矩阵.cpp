#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int rows=nums.size();
        int cols=nums[0].size();
        int len=rows*cols;
        vector<vector<int>> res(r,vector<int>(c,0));
        if(len/c!=r&&len%c!=0) return nums;
        for(int i=0;i<len;++i){
            res[i/c][i%c]=nums[i/cols][i%cols];
        }
        return res;
    }
};
void PrintMartrix(vector<vector<int>>& res){
    for(int i=0;i<res.size();++i){
        cout<<"[";
        for(int j=0;j<res[i].size();++j){
            cout<<" "<<res[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
}

int main(){
    vector<vector<int>> nums={{1,2,3,4}};
    Solution ans;
    vector<vector<int>> res=ans.matrixReshape(nums,1,4);
    PrintMartrix(res);
}
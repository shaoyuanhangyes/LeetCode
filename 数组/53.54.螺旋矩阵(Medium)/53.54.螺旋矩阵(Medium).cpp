#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int up=0,down=matrix.size()-1,left=0,right=matrix[0].size()-1;
        while(true){
            for(int i=left;i<=right;++i){
                res.push_back(matrix[up][i]);
            }
            if(++up>down) break;
            for(int i=up;i<=down;++i){
                res.push_back(matrix[i][right]);
            }
            if(--right<left) break;
            for(int i=right;i>=left;--i){
                res.push_back(matrix[down][i]);
            }
            if(--down<up) break;
            for(int i=down;i>=up;--i){
                res.push_back(matrix[i][left]);
            }
            if(++left>right) break;
        }
        return res;
    }
};

int main(){
    vector<vector<int>> matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    Solution ans;
    vector<int> res=ans.spiralOrder(matrix);
    for(auto x:res) cout<<x<<" ";
}
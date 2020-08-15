#include <iostream>
#include <vector>

using namespace std;

void PrintMartrix(vector<vector<int>>& res){
    for(int i=0;i<res.size();++i){
        cout<<"[";
        for(int j=0;j<res[i].size();++j){
            cout<<" "<<res[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
}
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;++i){
            vector<int> temp(i+1,1);
            res.push_back(temp);
        }
        for(int i=0;i<numRows;++i){
            for(int j=1;j<i;++j){
                res[i][j]=res[i-1][j-1]+res[i-1][j];
            }
        }
        return res;
    }
};
int main(){
    int numRows;
    cout<<"请输入生成杨辉三角的行数";
    cin>>numRows;
    Solution ans;
    vector<vector<int>> res=ans.generate(numRows);
    PrintMartrix(res);
}
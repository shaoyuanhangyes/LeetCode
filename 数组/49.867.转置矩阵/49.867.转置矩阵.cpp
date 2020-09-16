#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int rows=A.size();
        int cols=A[0].size();
        vector<vector<int>> res(cols,vector<int>(rows,0));
        for(int i=0;i<cols*rows;++i){
            res[i/rows][i%rows]=A[i%rows][i/rows];
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
    vector<vector<int>> A={{1,2,3},{4,5,6}};
    Solution ans;
    vector<vector<int>> res=ans.transpose(A);
    PrintMartrix(res);
}

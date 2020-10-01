#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int di[8]={-1,-1,-1,0,1,1,1,0};
        int dj[8]={-1,0,1,1,1,0,-1,-1};
        int count=0;
        for(int i=1;i<grid.size()-1;++i){
            for(int j=1;j<grid[0].size()-1;++j){
                if(grid[i][j]==5){
                    vector<int> around;
                    for(int k=0;k<8;k++){
                        around.push_back(grid[i+di[k]][j+dj[k]]);
                    }
                    count+=IsMagic(around);
                }
            }
        }
        return count;
    }
    bool IsMagic(vector<int>& v){
        for(int i=0;i<8;i+=2){
            if(m[i]==v[0]) return v==vector<int>(m.begin()+i,m.begin()+i+8)
                    ||v==vector<int>(m.rbegin()+7-i,m.rbegin()+15-i);
        }
        return false;
    }

private:
    vector<int> m={8,1,6,7,2,9,4,3,8,1,6,7,2,9,4,3};
};


int main(){
    vector<vector<int>> grid={{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    Solution ans;
    cout<<ans.numMagicSquaresInside(grid);
}
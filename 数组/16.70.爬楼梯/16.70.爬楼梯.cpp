#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> stairs(n+1,1);
        for(int i=2;i<=n;++i){
            stairs[i]=stairs[i-1]+stairs[i-2];
        }
        return stairs[n];
    }
};

int main(){
    cout<<"Please enter the number of stairs:";
    int num;
    cin>>num;
    Solution ans;
    cout<<"The class of steps are "<<ans.climbStairs(num)<<endl;
}
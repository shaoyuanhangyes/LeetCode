#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.empty()) return true;
        stack<int> st;
        int min=INT_MIN;
        for(int x:preorder){
            if(x<min) return false;
            while(!st.empty()&&x>st.top()){
                min=st.top();
                st.pop();
            }
            st.push(x);
        }
        return true;
    }
};

int main(){
    vector<int> preorder={5,2,1,3,6};
    Solution ans;
    cout<<ans.verifyPreorder(preorder);
}
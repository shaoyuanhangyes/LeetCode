#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(char c1,char c2){
        if(c1=='['&&c2==']') return true;
        if(c1=='{'&&c2=='}') return true;
        if(c1=='('&&c2==')') return true;
        return false;
    }
    bool isValid(string s) {
        if(s.length()%2==1) return false;
        if(s.empty()) return true;
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.length();++i){
            if(!st.empty()&&isMatch(st.top(),s[i])) st.pop();
            else st.push(s[i]);
        }
        return st.empty();
    }
};

int main(){
    string s="{[()]}";
    Solution ans;
    cout<<ans.isValid(s);
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> count(2001,0);
        vector<int> judge(1001,0);
        for(int i=0;i<arr.size();++i){
            count[arr[i]+1000]++;
        }
        for(int i=0;i<count.size();++i){
            if(count[i]){
                if(judge[count[i]]==0) judge[count[i]]=true;
                else return false;
            }
        }
        return true;
    }
};

int main(){
    vector<int> arr={1,2};
    Solution ans;
    cout<<ans.uniqueOccurrences(arr);
}
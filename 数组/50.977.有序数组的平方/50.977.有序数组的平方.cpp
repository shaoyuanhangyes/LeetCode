class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        int left=0,right=A.size()-1;
        int i=right;
        while(i>=0){
            if(-A[left]<A[right]){
                res[i]=A[right]*A[right];
                right--;
            }
            else {
                res[i]=A[left]*A[left];
                left++;
            }
            --i;
        }
        return res;
    }
};
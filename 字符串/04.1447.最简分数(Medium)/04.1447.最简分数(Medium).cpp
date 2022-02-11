#include <iostream>

#include <vector>

using namespace std;

class Solution {
  public:
   vector<string> simplifiedFractions(int n) {
      vector<string> res;
      for (int i = 2; i <= n; ++i) {
         for (int j = 1; j < i; ++j) {
            if (mygcd(i, j) == 1)
               res.push_back(to_string(j) + "/" + to_string(i));
         }
      }
      return res;
   }
   int mygcd(int a, int b) {
      return b == 0 ? a : mygcd(b, a % b);
   }
};

int main() {
   Solution ans;
   for (auto x : ans.simplifiedFractions(1))
      cout << x << " ";
   return 0;
}
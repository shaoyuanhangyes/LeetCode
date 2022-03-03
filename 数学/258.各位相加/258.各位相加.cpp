#include <iostream>

using namespace std;

// class Solution {
// public:
//    int addDigits(int num) {
//       while (num >= 10) {
//          int sum = 0;
//          while (num > 0) {
//             sum = sum + num % 10;
//             num /= 10;
//          }
//          num = sum;
//       }
//       return num;
//    }
// };

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};

int main() {
    int num;
    cout << "Please enter one number" << endl;
    cin >> num;
    Solution ans;
    cout << ans.addDigits(num);
    return 0;
}
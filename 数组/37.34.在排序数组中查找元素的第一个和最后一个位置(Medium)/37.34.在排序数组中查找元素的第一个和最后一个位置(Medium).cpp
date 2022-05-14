#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = FirstPosition(nums, target);
        if (first == -1) return vector<int>{-1, -1};
        int last = LastPosition(nums, target);
        return vector<int>{first, last};
    }

private:
    int FirstPosition(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        if (low < nums.size() && nums[low] == target) return low;
        return -1;
    }
    int LastPosition(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    Solution ans;
    vector<int> res = ans.searchRange(nums, 8);
    for (auto x : res) cout << x << " ";
}
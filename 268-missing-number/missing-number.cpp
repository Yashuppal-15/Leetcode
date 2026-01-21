#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // Step 01: Sum of nums
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // Step 02: Sum of range [0, N]
        int totalSum = (n * (n + 1)) / 2;

        // Step 03: Missing number
        int missingNum = totalSum - sum;
        return missingNum;
    }
};

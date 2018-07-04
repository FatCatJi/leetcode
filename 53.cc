// 53. Maximum Subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        for (int i = 0, n = nums.size(), sum = 0; i < n; ++i) {
            sum = max(sum, 0) + nums[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};

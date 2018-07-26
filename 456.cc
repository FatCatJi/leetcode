class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        for (int j = 1, minEle = nums[0]; j < (n-1); ++j) {
            if (nums[j] <= minEle) {
                minEle = nums[j];
            } else {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[k] < nums[j] && nums[k] > minEle) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

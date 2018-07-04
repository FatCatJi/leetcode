// Remove Duplicates from Sorted Array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), dupCnt = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i-1]) {
                dupCnt += 1;
            } else {
                nums[i-dupCnt] = nums[i];
            }
        }
        return n-dupCnt;
    }
};

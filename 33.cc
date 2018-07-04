class Solution {
private:
    int binSearch(const vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        int low = 0, high = n - 1;
        if (nums[low] > nums[high]) {
            // loop invariant:
            // low in [0, offeset) or high in [offset, n)
            while (low <= high) {
                int mid = low + (high-low)/2;
                if (nums[mid] >= nums[0]) {
                    // mid is in [0, offeset)
                    low = mid + 1;
                } else {
                    // mid is in [offset, n)
                    high = mid - 1;
                }
            }
            // After the loop stop, low is offset, high is offset-1
            if (target >= nums[0]) {
                // target is in [0, offeset), high is offset-1
                low = 0;
            } else {
                // target is in [offset, n), low is offset
                high = n - 1;
            }
        }
        return binSearch(nums, low, high, target);
    }
};

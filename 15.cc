// 15. 3Sum
class Solution {
private:
	vector<vector<int>> threeSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for (int i = 0, n = nums.size(); i < n; ++i) {
			if (i > 0 && nums[i] == nums[i-1]) {
				continue;
			}
			int t = target - nums[i];
			for (int j = i + 1, k = n - 1; j < k;) {
				while (j < k) {
					int sum = nums[j] + nums[k];
					if (sum == t) {
						break;
					} else if (sum < t) {
						++j;
					} else {
						--k;
					}
				}
				if (j < k) {
					vector<int> r(3);
					r[0] = nums[i];
					r[1] = nums[j];
					r[2] = nums[k];
					result.push_back(r);
					for (int num = nums[j]; num == nums[j]; ++j);
					for (int num = nums[k]; num == nums[k]; --k);
				}
			}
		}
		return result;
	}
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        return threeSum(nums, 0);
    }
};

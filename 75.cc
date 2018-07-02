class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
         * Invariant loop:
         * [0, zeroPos] all 0
         * (zeroPos, i) all 1
         * [i, twoPos) unknown
         * [twoPos, n) all 2
         */
        int zeroPos = -1, twoPos = nums.size();
		for (int i = 0; i < twoPos; ++i) {
			if (nums[i] == 0) {
				if (++zeroPos != i) {
					swap(nums[zeroPos], nums[i]);
				}
			} else if (nums[i] == 2) {
				while (nums[--twoPos] == 2 && twoPos > i);
				if (twoPos != i) {
					swap(nums[twoPos], nums[i]);
					if (nums[i] == 0) {
						if (++zeroPos != i) {
							swap(nums[zeroPos], nums[i]);
						}
					}
				}
			}
		}
    }
};

// 1. Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(0);
        unordered_map<int, int> map;
        for (int i = 0, size = nums.size(); i < size; ++i) {
            unordered_map<int, int>::iterator iter = map.find(target - nums[i]);
            if (iter != map.end()) {
                result.resize(2);
                result[0] = iter->second;
                result[1] = i;
                break;
            } else {
                if (map.find(nums[i]) == map.end()) {
                    map[nums[i]] = i;
                }
            }
        }
        return result;
    }
};

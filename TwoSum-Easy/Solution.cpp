class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;

        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            int complement = target - *it;
            if (map.find(complement) != map.end()) {
                return { map[complement],static_cast<int>(distance(nums.begin(),it))};
            }
            map[*it] = static_cast<int>(distance(nums.begin(),it));
       
        }
        throw invalid_argument("No two sum solution");
    }
};

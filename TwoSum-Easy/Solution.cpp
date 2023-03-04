#include<vector>
#include<unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;

        for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            int complement = target - *it;
            if (map.find(complement) != map.end()) {
                return { map[complement],static_cast<int>(std::distance(nums.begin(),it))};
            }
            map[*it] = static_cast<int>(std::distance(nums.begin(),it));
       
        }
        throw std::invalid_argument("No two sum solution");
    }
};

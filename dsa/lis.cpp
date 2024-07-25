#include <vector>
#include <algorithm>
//We use lower_bound to find the position where we can insert the current number while maintaining the sorted order of dp.
//lower bound returns iterator greater than or equal 

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        std::vector<int> dp;
        
        for (int num : nums) {
            auto it = std::lower_bound(dp.begin(), dp.end(), num);
            if (it == dp.end()) {
                dp.push_back(num);
            } else {
                *it = num;
            }
        }
        return dp.size();
    }
};




// {
// vector<int> temp;
//     for (auto num : nums) {
//         if (temp.empty() || num > temp.back()) {
//             temp.push_back(num);
//         } else {
//             auto it = lower_bound(temp.begin(), temp.end(), num);
//             *it = num;
//         }
//     }
//     return temp.size();
//     }
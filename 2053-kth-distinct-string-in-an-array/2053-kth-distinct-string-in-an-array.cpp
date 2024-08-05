class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for (const auto& i : arr) {
            mp[i]++;
        }
        
        vector<string> nums;
        for (const auto& i : arr) {
            if (mp[i] == 1) {
                nums.push_back(i);
            }
        }
        
        if (nums.size() < k) {
            return "";
        } else {
            return nums[k - 1];
        }
    }
};

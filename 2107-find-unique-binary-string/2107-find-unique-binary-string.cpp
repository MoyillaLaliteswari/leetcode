class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        unordered_set<string> existing(nums.begin(), nums.end());
        for (int i = 0; i < (1 << n); i++) {
            string candidate = "";
            for (int j = 0; j < n; j++) {
                candidate += (i & (1 << j)) ? '1' : '0';
            }
            if (existing.find(candidate) == existing.end()) {
                return candidate; 
            }
        }
        return ""; 
    }
};

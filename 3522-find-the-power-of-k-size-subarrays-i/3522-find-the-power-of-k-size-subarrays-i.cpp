class Solution {
public:
    int maxi(vector<int>& nums, int start, int k) {
        for (int i = start + 1; i < start + k; i++) {
            if (nums[i] != nums[i - 1] + 1) { // If not consecutive, return -1
                return -1;
            }
        }
        return nums[start + k - 1]; // Return the maximum element in the valid subarray
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> p;
        for (int i = 0; i <= nums.size() - k; i++) { // Iterate over valid starting points
            int r = maxi(nums, i, k);
            p.push_back(r); // Append the result for the subarray
        }
        return p;
    }
};

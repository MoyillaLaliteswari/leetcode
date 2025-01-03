class Solution {
public:
    int waysToSplitArray(vector<int>& nums){
        int n=nums.size();
        long long totalSum = 0; 
        long long prefixSum = 0; 
        int count = 0; 
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        for (int i = 0; i < n - 1; i++) {
            prefixSum += nums[i];
            long long suffixSum = totalSum - prefixSum; 
            if (prefixSum >= suffixSum) { 
                count++;
            }
        }

        return count;
    }
};

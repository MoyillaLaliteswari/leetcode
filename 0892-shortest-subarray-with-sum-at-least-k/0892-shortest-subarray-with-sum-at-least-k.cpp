class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq; // Store indices of prefix sums
        vector<long long> prefixSum(n + 1, 0); // Prefix sum array

        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        int result = INT_MAX;

        for (int i = 0; i <= n; ++i) {
            // Check if any subarray sum >= k can be formed
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                result = min(result, i - dq.front());
                dq.pop_front();
            }

            // Maintain deque order (non-decreasing prefix sums)
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }

            // Add the current index to deque
            dq.push_back(i);
        }

        return (result == INT_MAX) ? -1 : result;
    }
};

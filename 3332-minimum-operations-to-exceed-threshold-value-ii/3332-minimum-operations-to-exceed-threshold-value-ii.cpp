class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt = 0;
        if (nums.size() < 2) return 0;
        priority_queue<long long, vector<long long>, greater<long long>> p;
        for (int i = 0; i < nums.size(); i++) {
            p.push(nums[i]);
        }
        if (p.top() >= k) return 0;
        while (p.size() > 1 && p.top() < k) {
            long long l1 = p.top();
            p.pop();
            long long l2 = p.top();
            p.pop();
            long long res = l1 * 2 + l2;
            p.push(res);
            cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>p(n,0);
        for(int i=1;i<n;i++){
            p[i]=p[i-1];
            if((nums[i-1]%2==0 and nums[i]%2==0) || (nums[i-1]%2!=0 and nums[i]%2!=0)){
                p[i]++;
            }
        }
        vector<bool>ans;
        for(auto& q:queries){
            int left=q[0],right=q[1];
            int s=p[right]-(left>0 ? p[left]:0);
            ans.push_back(s==0);
        }
        return ans;
    }
};
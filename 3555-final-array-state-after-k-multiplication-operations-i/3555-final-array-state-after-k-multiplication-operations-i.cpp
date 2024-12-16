class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(nums.empty()) return nums;
        while(k!=0){
            auto l=min_element(nums.begin(),nums.end());
            if(l==nums.end()) break;
            int r=distance(nums.begin(),l);
            nums[r]=(*l)*multiplier;
            k--;
        }
        return nums;
    }
};
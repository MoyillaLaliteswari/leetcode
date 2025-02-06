class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int cnt=0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int mul=nums[i]*nums[j];
                cnt+=8*mp[mul];
                mp[mul]++;
            }
        }
        return cnt;
    }
};
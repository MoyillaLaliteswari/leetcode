class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>valueI;
        int n=nums.size();
        for(int i=0;i<n;i++){
            valueI.push_back({nums[i],i});
        }
        sort(valueI.begin(),valueI.end());
        vector<vector<pair<int,int>>>p;
        p.push_back({valueI[0]});
        for(int i=1;i<n;i++){
            if(valueI[i].first-valueI[i-1].first<=limit){
                p.back().push_back(valueI[i]);
            }
            else{
                p.push_back({valueI[i]});
            }
        }
        for(const auto& num:p){
            vector<int>arr;
            for(const auto&[value,index]:num){
                arr.push_back(index);
            }
            sort(arr.begin(),arr.end());
            for(size_t i=0;i<arr.size();i++){
                nums[arr[i]]=num[i].first;
            }
        }
        return nums;
    }
};
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>ans;
        while(i<n1 and j<n2){
            if(nums1[i]<nums2[j]) 
                i++;
            else if(nums2[j]<nums1[i]){
                j++;
            }
            else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};
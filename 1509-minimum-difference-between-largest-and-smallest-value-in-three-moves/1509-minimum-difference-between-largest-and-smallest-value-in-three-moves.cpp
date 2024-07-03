class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4){
            return 0;
        }
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int m=INT_MAX;
        for(int i=0;i<=3;i++){
            m=min((abs(nums[n-4+i]-nums[i])),m);
        }
        return m;
//         if(n==5){
            
//             for(int i=1;i<n;i++){
//                 m=min((nums[i]-nums[i-1]),m);
//             }
//             return m;
//         }
//         else{
//             int c=0;
//             int k;
//             for(int i=0;i<n-1;i++){
//                 if(nums[i]!=nums[i+1]){
//                     c++;
//                 }
//                 else k=nums[i];
//             }
//             int l;
//             if(c==5){
//                 for(int i=1;i<n;i++){
//                     m=nums[i]-nums[i-1];
//                     if(m<mini){
//                         mini=m;
//                         l=nums[i-1];
//                     }
//                 }
//                 if(l==k) return mini;
//             }  
//         }
//         int a=nums[n-4]-nums[0];
//         int b=nums[n-1]-nums[3];
//         if(a<b) return a;
//         return b;
    }
};
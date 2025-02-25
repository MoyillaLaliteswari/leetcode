class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int cnt=0;
        int sum=0;
        int MOD=1000000007;
        int odd=0,even=1;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2==1){
                cnt=(cnt+even)%MOD;
                odd++;
            }
            else{
                cnt=(cnt+odd)%MOD;
                even++;
            }
        }
        return cnt;
    }
};
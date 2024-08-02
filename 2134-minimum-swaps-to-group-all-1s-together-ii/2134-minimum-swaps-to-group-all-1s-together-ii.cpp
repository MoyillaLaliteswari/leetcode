class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int onesCount = 0;
        
       
        for (int num : nums) {
            onesCount += num;
        }
        
       
        if (onesCount == 0) return 0;
        
       
        vector<int> numsDouble = nums;
        numsDouble.insert(numsDouble.end(), nums.begin(), nums.end());
        
        int maxOnesInWindow = 0;
        int currentOnesInWindow = 0;
        int left = 0;
        
       
        for (int right = 0; right < numsDouble.size(); ++right) {
            if (numsDouble[right] == 1) {
                currentOnesInWindow++;
            }
            
            
            if (right - left + 1 > onesCount) {
                if (numsDouble[left] == 1) {
                    currentOnesInWindow--;
                }
                left++;
            }
            
            maxOnesInWindow = max(maxOnesInWindow, currentOnesInWindow);
        }
        
        
        return onesCount - maxOnesInWindow;
    }
};


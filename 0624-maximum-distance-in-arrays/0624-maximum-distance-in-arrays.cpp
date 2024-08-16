class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0].front();
        int maxi = arrays[0].back();
        int maxDist = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            int currentMin = arrays[i].front();
            int currentMax = arrays[i].back();

            
            maxDist = max(maxDist, max(abs(currentMax - mini), abs(maxi - currentMin)));

            // Update the global minimum and maximum
            mini = min(mini, currentMin);
            maxi = max(maxi, currentMax);
        }

        return maxDist;
    }
};

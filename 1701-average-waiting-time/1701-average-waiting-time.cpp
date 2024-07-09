class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double rem = static_cast<double>(customers[0][0]) +                                         static_cast<double>(customers[0][1]);
        double ag = rem - static_cast<double>(customers[0][0]);
        double n = static_cast<double>(customers.size());
        
        for (int i = 1; i < customers.size(); ++i) {
            rem = max(rem, static_cast<double>(customers[i][0])) +                     static_cast<double>(customers[i][1]);
            ag += rem - static_cast<double>(customers[i][0]);
        }
        
        return ag / n;
    }
};

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> mappedNums;
        
        for(int num : nums) {
            int originalNum = num;
            string mappedStr = "";
            
            do {
                int digit = num % 10;
                mappedStr = char('0' + mapping[digit]) + mappedStr;
                num /= 10;
            } while(num != 0);
            
            int mappedNum = stoi(mappedStr);
            mappedNums.push_back({mappedNum, originalNum});
        }
        
        sort(mappedNums.begin(), mappedNums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });
        
        vector<int> result;
        for(const auto& p : mappedNums) {
            result.push_back(p.second);
        }
        
        return result;
    }
};

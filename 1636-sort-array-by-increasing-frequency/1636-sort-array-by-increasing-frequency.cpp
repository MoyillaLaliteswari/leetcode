

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
       
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        
        vector<pair<int, int>> freqVec;
        for (auto& it : freq) {
            freqVec.push_back(it);
        }

       
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });

        
        vector<int> result;
        for (auto& it : freqVec) {
            result.insert(result.end(), it.second, it.first);
        }

        return result;
    }
};

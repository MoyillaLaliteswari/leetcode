class Solution {
public:
    int countSeniors(vector<string>& d) {
        int cnt = 0;
        for (const auto& entry : d) {
            
            string age_str = entry.substr(11, 2);
            int age = stoi(age_str); 
            cout<<age;
            if (age > 60) {
                cnt++;
            }
        }
        return cnt;
    }
};

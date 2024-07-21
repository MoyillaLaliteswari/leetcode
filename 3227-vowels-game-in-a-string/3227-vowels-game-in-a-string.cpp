class Solution {
public:
    bool doesAliceWin(string s) {
        int n = s.size();
        int vowelsCount = 0;
        
        
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowelsCount++;
            }
        }
        if(vowelsCount>0){
            return true;
        }
        return false;
    }
};


        
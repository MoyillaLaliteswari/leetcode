class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int s=0;
        for(int i=0;i<derived.size();i++){
            s^=derived[i];
        }
        return s==0;
    }
};
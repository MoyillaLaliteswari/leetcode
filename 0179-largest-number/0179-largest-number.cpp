class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>l;
        for(int i=0;i<nums.size();i++){
            l.push_back(to_string(nums[i]));
        }
        auto compare = [](const string &x, const string &y) {
            return x + y > y + x;
        };
        sort(l.begin(),l.end(),compare);
        if(l[0]=="0") return "0";
        string result="";
        for(string i:l){
            result+=i;
        }
        return result;
    }
};
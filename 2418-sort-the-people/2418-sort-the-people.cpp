class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string>mp;
        for(int i=0;i<names.size();i++){
            mp[heights[i]]=names[i];
        }
        int i=0; 
        for (const auto &ch:mp){
            names[i]=ch.second;
            i++;
        }
        reverse(names.begin(),names.end());
        return names;
    }
};
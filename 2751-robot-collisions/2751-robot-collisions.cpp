class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            v.push_back(i);
        }
        auto compare=[&](int v1,int v2){
            return positions[v1]<=positions[v2];
        };
        
        sort(v.begin(),v.end(),compare);
        stack<int>st;
        for(auto it:v){
            if(directions[it]=='R'){
                st.push(it);
            }else{
                while(!st.empty() and healths[it]>0){
                    if(healths[it]>healths[st.top()]){
                        healths[it]--;
                        healths[st.top()]=0;
                        st.pop();
                    }
                    else if(healths[it] <healths[st.top()]){
                        healths[it]=0;
                        healths[st.top()]--;
                    }
                    else{
                        healths[it]=0;
                        healths[st.top()]=0;
                        st.pop();
                    }
                }
            }
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            if(healths[i]>0){
                res.push_back(healths[i]);
            }
        }
        return res;
    }
};
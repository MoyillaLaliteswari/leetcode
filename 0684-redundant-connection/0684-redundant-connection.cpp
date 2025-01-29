class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>g;
        auto isConnected=[&](int u,int v){
            unordered_set<int>visited;
            stack<int>st;
            st.push(u);
            while(!st.empty()){
                int n=st.top();
                st.pop();
                if(visited.count(n)) continue;
                visited.insert(n);
                if(n==v)return true;
                for(int num:g[n]){
                    st.push(num);
                }
            }
            return false;
        };
        for(const auto& edge:edges){
            int u=edge[0] , v=edge[1];
            if(g.count(u) && g.count(v) && isConnected(u,v)){
                return edge;
            }
            g[u].push_back(v);
            g[v].push_back(u);
        }
        return {};
    }
};
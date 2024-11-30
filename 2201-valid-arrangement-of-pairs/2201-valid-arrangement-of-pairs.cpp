class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>graph;
        unordered_map<int,int>inOutDegree;

        for(const auto& pair:pairs){
            graph[pair[0]].push_back(pair[1]);
            inOutDegree[pair[0]]++;
            inOutDegree[pair[1]]--;
        }

        int startNode=pairs[0][0];
        for(const auto& [node,degree]:inOutDegree){
            if(degree==1){
                startNode=node;
                break;
            }
        }
        vector<int>path;
        stack<int>st;
        st.push(startNode);
        while(!st.empty()){
            auto& rel=graph[st.top()];
            if(rel.empty()){
                path.push_back(st.top());
                st.pop();
            }
            else{
                int nextNode=rel.back();
                st.push(nextNode);
                rel.pop_back();
            }
        }
        vector<vector<int>>arr;
        int n=path.size();
        arr.reserve(n-1);
        for(int i=n-1;i>0;i--){
            arr.push_back({path[i],path[i-1]});
        }
        return arr;
    }
};
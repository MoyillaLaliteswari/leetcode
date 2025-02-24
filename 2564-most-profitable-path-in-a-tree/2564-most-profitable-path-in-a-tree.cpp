class Solution {
public:
    bool fillbob(int node ,int parent,vector<int>&path,vector<vector<int>>&graph){
        if(node==0) return true;
        for(int num:graph[node]){
            if(num!=parent){
                path.push_back(node);
                if(fillbob(num,node,path,graph)) return true;
                path.pop_back();
            }
        }
        return false;
    }
    int getscore(int node,int parent,int curr,vector<int>&bob,vector<vector<int>>&graph,int timestamp,vector<int>&amount){
        if(bob[node]==-1 || bob[node]>timestamp){
            curr+=amount[node];
        }else if(bob[node]==timestamp){
            curr+=amount[node]/2;
        }
        if(graph[node].size()==1 and node!=0) return curr;
        int maxi=INT_MIN;
        for(int num:graph[node]){
            if(num!=parent){
                maxi=max(maxi,getscore(num,node,curr,bob,graph,timestamp+1,amount));
            }
        }
        return maxi;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<vector<int>>graph(n);
        for(auto& edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int>bobp(n,-1);
        vector<int>path;
        fillbob(bob,-1,path,graph);
        for(int i=0;i<path.size();i++){
            bobp[path[i]]=i;
        }
        return getscore(0,-1,0,bobp,graph,0,amount);
    }
};
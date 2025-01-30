class Solution {
    vector<int>color;
    vector<vector<int>>adj;
    int n;
    bool help_1(int node,int c,vector<int>&component){
        color[node]=c;
        component.push_back(node);
        for(int num:adj[node]){
            if(color[num]==c) return false;
            if(color[num]== -1 && !help_1(num,1-c,component))return false;
        }
        return true;
    }
    int help_2(const vector<int>&component){
        int maxDepth=0;
        for(int start:component){
            vector<int>depth(n,-1);
            queue<int>q;
            q.push(start);
            depth[start]=0;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(int num:adj[node]){
                    if(depth[num]==-1){
                        depth[num]=depth[node]+1;
                        maxDepth=max(maxDepth,depth[num]);
                        q.push(num);
                    }
                }
            }
        }
        return maxDepth+1;
    }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        this->n=n;
        color.assign(n,-1);
        adj.resize(n);
        for(auto& e:edges){
            int u=e[0]-1,v=e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>>components;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                components.emplace_back();
                if(!help_1(i,0,components.back()))
                    return -1;
            }
        }
        int total=0;
        for(auto& comp:components){
            total+=help_2(comp);
        }
        return total;
    }
};
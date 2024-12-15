class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int e) {
        auto comparator=[](pair<int,int>&a,pair<int,int>&b){
            double benefita=(double)(a.first +1)/(a.second+1)-(double)a.first/a.second;
            double benefitb=(double)(b.first+1)/(b.second+1)-(double)b.first/b.second;
            return benefita<benefitb;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comparator)>pq(comparator);
        for(auto& c:classes){
            pq.push({c[0],c[1]});
        }
        while(e>0){
            auto [passi,totali]=pq.top();
            pq.pop();
            pq.push({passi+1,totali+1});
            e--;
        }
        double t=0.0;
        while(!pq.empty()){
            auto [pass,total]=pq.top();
            pq.pop();
            t+=(double)pass/total;
            
        }
        return t/classes.size();

    }
};
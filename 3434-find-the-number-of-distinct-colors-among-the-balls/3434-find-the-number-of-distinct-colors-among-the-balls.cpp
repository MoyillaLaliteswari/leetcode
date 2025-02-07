class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>res;
        res.reserve(queries.size());
        map<int,int>ball,col;
        int cnt=0;
        for(auto &q:queries){
            int pos=q[0],c=q[1];
            if(ball.count(pos)){
                if(--col[ball[pos]]==0)cnt--;
            }
            ball[pos]=c;
            if(++col[c]==1) cnt++;
            res.push_back(cnt);
        }
        return res;
    }
};
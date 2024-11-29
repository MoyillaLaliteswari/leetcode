class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1]>1 && grid[1][0]>1) return -1;
        int rows = grid.size();
        int cols=grid[0].size();

        priority_queue<pair<int,pair<int,int>>,
                        vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>>>pq;
        pq.push({0, {0, 0}});
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        visited[0][0]=1;
        vector<pair<int,int>>moves={{0, 1}, {0, -1}, {1, 0}, {-1, 0 }};

        while(!pq.empty()) {
            auto curr = pq.top();
            int currTime = curr.first;
            int currRow = curr.second.first;
            int currCol = curr.second.second;
            pq.pop();
            if(currRow == rows - 1 and currCol == cols - 1){
                return currTime;
            }
            for(auto move : moves) {
                int nextRow = move.first + currRow;
                int nextCol = move.second + currCol;
                if(nextRow >= 0 and nextCol >= 0 and nextRow < rows  and    nextCol < cols and !visited[nextRow][nextCol]){
                    int waitTime = ((grid[nextRow][nextCol]-currTime) % 2 ==0) ? 1 : 0 ;
                    int nextTime = max(currTime + 1, grid[nextRow][nextCol] + waitTime);
                    pq.push({nextTime , {nextRow, nextCol}});
                    visited[nextRow][nextCol] = 1;
                }
            }    
        }
        return -1;
    }
};
class Solution {
public:
    int num(string & tiles,vector<bool>&used){
        int cnt=0;
        for(int i=0;i<tiles.size();i++){
            if(used[i] || (i>0 and tiles[i]==tiles[i-1] and !used[i-1]))continue;
            used[i]=true;
            cnt+= (1+num(tiles,used));
            used[i]=false;
        }
        return cnt;
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        vector<bool>used(tiles.size(),false);
        return num(tiles,used);
    }
};
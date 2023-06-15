class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int ans = 0;
        for(int i = 0;i<grid.size();++i)
        {
            for(int j = 0;j<grid.size();++j)
            {
                int p = 0;
                while(p<grid.size())
                {
                    if(grid[i][p]!=grid[p][j])break;
                    ++p;
                }
                if(p==grid.size())
                    ans++;
            }
        }
        return ans;
        
    }
};


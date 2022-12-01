class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int ans = m[0][0];
        for(int i = 1;i<m.size();++i)
        {
            ans = INT_MAX;
            for(int j=0;j<m.size();++j)
            {
                int p = m[i-1][j];
                if(j-1>=0)
                    p = min(p,m[i-1][j-1]);
                if(j+1<m.size())
                    p = min(p,m[i-1][j+1]);
                m[i][j]+=p;
                ans= min(m[i][j],ans);
            }
        }
        return  ans;
    }
};
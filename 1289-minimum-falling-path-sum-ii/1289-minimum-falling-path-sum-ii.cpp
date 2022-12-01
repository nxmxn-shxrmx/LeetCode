class Solution {
public:
    int minFallingPathSum(vector<vector<int>>&m) {
         int ans = m[0][0];
        for(int i = 1;i<m.size();++i)
        {
            ans = INT_MAX;
            for(int j=0;j<m.size();++j)
            {
                int p = INT_MAX;
                int k = j-1;
                while(k>=0)
                    p = min(p,m[i-1][k]),k--;
                k =j+1;
                while(k<m.size())
                    p = min(p,m[i-1][k]),k++;
                m[i][j]+=p;
                ans= min(m[i][j],ans);
            }
        }
        return  ans;
    }
};
class Solution {
public:
  
    int minimumTotal(vector<vector<int>>& t) {
    int ans = INT_MAX; ans= t[0][0];
        for(int i = 1;i<t.size();++i)
        {t[i][0]+=t[i-1][0];ans = t[i][0];for(int j =1;j<t[i-1].size();++j)t[i][j]=min(t[i-1][j-1],t[i-1][j])+t[i][j],ans=min(ans,t[i][j]);t[i][t[i-1].size()]+=t[i-1][t[i-1].size()-1];ans = min(ans,t[i][t[i-1].size()]);
        }return ans;
    }
};
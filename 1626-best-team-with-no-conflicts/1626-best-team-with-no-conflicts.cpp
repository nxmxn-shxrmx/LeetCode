class Solution {
public:
    int dp[1002][1002];
    int f(int i,vector<vector<int>>&v,int age)
    {
        if(i==v.size())return 0;
        if(dp[i][age]!=-1)return dp[i][age];
        int u =0;
        if(age<=v[i][1])
            u = f(i+1,v,max(v[i][1],age))+v[i][0];
        return dp[i][age]=max(f(i+1,v,age),u);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>>v;
        int mx =0;
        for(int i = 0;i<scores.size();++i)
            v.push_back({scores[i],ages[i]}),mx = max(v[i][1],mx);
        sort(v.begin(),v.end());
        for(int i=v.size()-1;~i;--i)
        {
            for(int j =mx;~j;--j)
            {
                 int u =0;
                if(j<=v[i][1])
                u = dp[i+1][max(v[i][1],j)]+v[i][0];
                 dp[i][j]=max(dp[i+1][j],u); 

            }
        }
        return dp[0][0];
    }
};
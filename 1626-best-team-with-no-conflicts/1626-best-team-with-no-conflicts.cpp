class Solution {
public:
    int dp[1001][1001];
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
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i<scores.size();++i)
            v.push_back({scores[i],ages[i]});
        sort(v.begin(),v.end());
        return f(0,v,0);
    }
};
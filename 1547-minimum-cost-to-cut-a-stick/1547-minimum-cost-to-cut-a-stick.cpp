class Solution {
public:
    // map<pair<int,int>,int>dp;
//     long long dp[103][103];
//     long long findmin(int l,int r,vector<int>cuts)
//     {
//         if(r-l<=1)
//             return 0;
//         if(dp[l][r])
//             return dp[l][r];
    
//      dp[l][r]= INT_MAX;
        
//         for(int i =l+1;i<r;++i)            
//             dp[l][r] = min(dp[l][r],cuts[r]-cuts[l]+findmin(i,r,cuts)+findmin(l,i,cuts));       
        
//         if(dp[l][r]==INT_MAX)
//             return dp[l][r]=0;
//         return dp[l][r];
//     }
//     int minCost(int n, vector<int>& cuts) {
        
//         cuts.push_back(0);
//         cuts.push_back(n);
//         sort(cuts.begin(),cuts.end());
//         return findmin(0,cuts.size()-1,cuts);
//     }
    int dp[102][102] = {};
int dfs(vector<int>& cuts, int i, int j) {
    if (j - i <= 1)
        return 0;
    if (!dp[i][j]) {
        dp[i][j] = INT_MAX;
        for (auto k = i + 1; k < j; ++k)
            dp[i][j] = min(dp[i][j], 
                cuts[j] - cuts[i] + dfs(cuts, i, k) + dfs(cuts, k, j));
    }
    return dp[i][j];
}
int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(begin(cuts), end(cuts));
    return dfs(cuts, 0, cuts.size() - 1);
}
};

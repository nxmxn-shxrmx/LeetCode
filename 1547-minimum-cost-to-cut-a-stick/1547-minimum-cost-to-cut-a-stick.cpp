class Solution {
public:
    int dp[102][102]={};
    int find(int i,int j,vector<int>&cuts)
    {
        if(j-i<=1)
            return 0;
        if(!dp[i][j])
        {
            dp[i][j]=INT_MAX;
            for(int k = i+1;k<j;++k)
                dp[i][j]=min(dp[i][j],cuts[j]-cuts[i]+find(i,k,cuts)+find(k,j,cuts));
            
        }
        return dp[i][j];
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        
        return find(0,cuts.size()-1,cuts);
    }
};
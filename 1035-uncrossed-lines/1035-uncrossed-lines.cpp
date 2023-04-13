class Solution {
public:
     int dp[501][501];
//     int f(int i,int j,vector<int>&v1,vector<int>&v2)
//     {
//         if(i==v1.size()|| j==v2.size())return 0;
//         if(dp[i][j]!=-1)return dp[i][j];
//         if(v1[i]==v2[j])
//             return dp[i][j]=max(f(i+1,j+1,v1,v2)+1,max(f(i,j+1,v1,v2),f(i+1,j,v1,v2)));
        
//         return dp[i][j]=max(f(i,j+1,v1,v2),f(i+1,j,v1,v2));
//     }
    int maxUncrossedLines(vector<int>& v1, vector<int>& v2) {
        
        for(int i =v1.size()-1;~i;--i)
        {
            for(int j = v2.size()-1;~j;--j)
            {
                if(v1[i]==v2[j])
                    dp[i][j] = max(dp[i+1][j+1]+1,max(dp[i][j+1],dp[i+1][j]));
                else dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};
class Solution {
public:
    
//     int f(int i,int j,vector<int>&v1,vector<int>&v2)
//     {
//         if(i==v1.size()|| j==v2.size())return 0;
//         if(dp[i][j]!=-1)return dp[i][j];
//         if(v1[i]==v2[j])
//             return dp[i][j]=max(f(i+1,j+1,v1,v2)+1,max(f(i,j+1,v1,v2),f(i+1,j,v1,v2)));
        
//         return dp[i][j]=max(f(i,j+1,v1,v2),f(i+1,j,v1,v2));
//     }
    int maxUncrossedLines(vector<int>& v1, vector<int>& v2) {
        vector<int>pre(v2.size()+1);
        vector<int>cur(v2.size()+1);
        for(int i =v1.size()-1;~i;--i)
        {
            for(int j = v2.size()-1;~j;--j)
            {
                if(v1[i]==v2[j])
                    cur[j] = max(pre[j+1]+1,max(cur[j+1],pre[j]));
                else cur[j] = max(cur[j+1],pre[j]);
            }
            pre =cur;
        }
        return cur[0];
    }
};
class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size();
        int m = t2.size();
        
        vector<int>cur(m+1,0);
        vector<int>pre(m+1,0);
        
        for(int i = 1;i<=n;++i)
        {
            for(int j = 1;j<=m;++j)
            {
                if(t1[i-1]==t2[j-1])
                    cur[j] = pre[j-1]+1;
                else
                    cur[j] = max(pre[j],cur[j-1]);
            }
            pre =cur;
        }
        
        return pre[m];
    }
};
class Solution {
public:
    
//     int f(int i,long long ans,vector<long long>&v,int t)
//     {
//         if(i==v.size())
//         {
//             if(ans==t)
//                 return  0;
//             return 100;
//         }
//         if(dp[i][ans]!=-1)return dp[i][ans];
     
//         return dp[i][ans] = min(f(i+1,ans,v,t),f(i+1,ans|v[i],v,t)+1);
//     }
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& p) {
        
        map<string,int>r;
        for(int i = 0;i<req.size();++i)
            r[req[i]]=i;
        vector<long long>v;
        for(auto c:p)
        {
            long long ans = 0;
            for(auto x:c)
                ans |= 1<<r[x];
            v.push_back(ans);
        }
        long long t=req.size();
        
        t = (1<<t)-1;
        vector<vector<int>>dp(p.size()+1,vector<int>(t+1));
        for(int i = 0;i<t;++i)
            dp[p.size()][i]=100;
        for(int i = p.size()-1;~i;--i)
        {
            for(int j = t-1;~j;--j)
            {
                dp[i][j] = min(dp[i+1][j],dp[i+1][j|v[i]]+1);   
            }
        }
    
        int i = 0;
        int j = 0;
        vector<int>ans;
        while(ans.size()!=dp[0][0])
        {
            
            if(dp[i+1][j|v[i]]+1==dp[i][j])
            {
                    ans.push_back(i);
                    j|=v[i],i+=1;
                continue;
            }
            if(dp[i+1][j]+1==dp[i][j])
            {            
                    ans.push_back(i);
                i+=1;
                continue;
            }
            if(dp[i+1][j]==100)j|=v[i],i+=1;
            else i+=1;
        }
        return ans;
    }
};


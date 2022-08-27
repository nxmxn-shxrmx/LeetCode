class Solution {
public:
    #define ll long long
    vector<int>v;
    int dp[1<<17];
    bool sub(int t,int k,int i,int s,vector<int>n,ll lo)
    {
        // cout<<lo<<" ";
        if(k==0)
        {
            // cout<<lo<<"\n";
            return 1;
        }
        if(t==s)
            return dp[lo]=sub(0,k-1,0,s,n,lo);
        if(dp[lo]!=-1)
            return dp[lo];
        for(int j = i;j<n.size();++j)
        {
            if(v[j]==1 ||  t+n[j]>s)
                continue;
            v[j]=1;
            bool p =sub(t+n[j],k,j+1,s,n,lo|(1<<j));
            if(p)
            {
                // cout<<lo<<"\n";
                return dp[lo]=1;
            }
             v[j]=0;
        }
        return dp[lo]=0;
    }
    bool canPartitionKSubsets(vector<int>& n, int k) {
        v = vector<int>(n.size());
        int s = 0;
        for(auto c:n)
            s+=c;
        if(s%k==1)
            return false;
        s/=k;
       memset(dp,-1,sizeof(dp));
        sort(n.rbegin(),n.rend());
         
        
        return sub(0,k,0,s,n,0);;
    }
};
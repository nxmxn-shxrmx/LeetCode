class Solution {
public:
    int dp[100001][3];
    bool f(int i,int ct,vector<int>&v)
    {
        if(i==v.size()-1)
        {
            if(ct==2)
            {
                if(v[i]==(v[i-1]+1) && (v[i]==v[i-2]+2))return 1;
                
                if(v[i]==v[i-1] && v[i]==v[i-2])return 1;
                
                return 0;
            }
            if(ct==1 && v[i]==v[i-1])return 1;
            
            return 0;
        }
        if(dp[i][ct]!=-1)return dp[i][ct];
        if(ct==0)
            return dp[i][ct]=f(i+1,1,v);
        if(ct==1)
        {
            if(v[i]==v[i-1])return dp[i][ct]= f(i+1,ct+1,v)||f(i+1,0,v);
            if(v[i]==v[i-1]+1)return dp[i][ct]=f(i+1,ct+1,v);
            
            return dp[i][ct]=0;
        }
        
        if(v[i]==(v[i-1]+1) && (v[i]==v[i-2]+2))return dp[i][ct]= f(i+1,0,v);
    
         if(v[i]==v[i-1] && v[i]==v[i-2])return dp[i][ct]= f(i+1,0,v);
        
        return dp[i][ct]=0;       
        
           }
    bool validPartition(vector<int>& nums) {
        if(nums.size()==1)return 0;
        memset(dp,-1,sizeof(dp));
        return f(0,0,nums);
    }
};
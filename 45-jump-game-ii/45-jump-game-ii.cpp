class Solution {
public:
    int jump(vector<int>& nums) {
        vector<long long>g(nums.size(),INT_MAX);
        g[nums.size()-1]=0;
        
        for(int i= nums.size()-2;~i;--i)        
        {
            long long k = nums[i];
            int j = 0;
            if(i+nums[i]>=nums.size()-1)
                g[i]=1;
            else if(nums[i]==0)
                g[i]=-1;
            
            else
            {
                for(int j =1;j<=k && (j+i)<nums.size();++j)
                {
                    if(g[i+j]==-1 || g[i+j]==INT_MAX)
                        continue;
                    
                    g[i] = min(g[i+j]+1,g[i]);
                    
                }
            }
            
        }
        return g[0];
    }
};
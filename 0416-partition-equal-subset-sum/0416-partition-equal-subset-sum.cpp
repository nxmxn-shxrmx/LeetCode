class Solution {
public:
  
    bool canPartition(vector<int>& nums) {
        int u  =0;
        for(auto c:nums)
            u+=c;
        if(u%2)return 0;
        
        u/=2;
        vector<int>pre(u+1,0);
        vector<int>cur(u+1,0);
        pre[0]=1;
        for(int i = 1;i<=nums.size();++i)
        {
            for(int j =1;j<=u;++j)
            {
                if(j-nums[i-1]>=0)
                    cur[j]|=pre[j-nums[i-1]];
                cur[j]|=pre[j];
            }
            pre=cur;
        }
        return cur[u];
    }
};
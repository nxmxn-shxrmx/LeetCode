class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v(nums.size());
        int c  =0;
        
        for(int i = 0;i<nums.size();++i)
        {
            v[i]=1;
            for(int j = 0;j<i;++j)
            {
                if(nums[j]<nums[i])
                    v[i] = max(v[j]+1,v[i]);
            }
            c = max(c,v[i]);
        }
        
        return c;
            
    }
};
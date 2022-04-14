class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v(nums.size());
        
        for(int i = 0;i<nums.size();++i)
        {
            v[i]=1;
            for(int j = 0;j<i;++j)
            {
                if(nums[j]<nums[i])
                    v[i] = max(v[j]+1,v[i]);
            }
        }
        int c = 0;
        for(auto x:v)
            c = max(c,x);
        
        return c;
            
    }
};
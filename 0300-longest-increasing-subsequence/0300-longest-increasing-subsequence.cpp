class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>v;
        int c=0;
        for(int i = 0;i<nums.size();++i)
        {
            int l = 0,r=c;
            while(l<r)
            {
                int m = (l+r)/2;
                if(v[m]<nums[i])
                {
                    l = m+1;
                }
                else
                {
                    r = m;
                }
            }
            if(l==c)
                c++,v.push_back(nums[i]);
            else
                v[l]=nums[i];
        }
        return c;
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       int c=0;
        vector<int>v(nums.size());
        for(auto x:nums)
        {
            int l =0,r = c;
            while(l!=r)
            {
                int m = (l+r)/2;
                if(v[m]>=x)
                    r =  m;
                else
                    l = m+1;
            }
            v[l]=x;
            if(l==c)
                c++;
        }
        return c;
            
    }
};
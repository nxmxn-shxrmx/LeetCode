class Solution {
public:
    bool check(int m,vector<int>&nums)
    {
        long long u =0;
        for(int i = nums.size()-1;i>=1;--i)
        {
            long long p =nums[i]+u;
            if(p<=m)
            {
                u=0;
                continue;
            }
            u+=(nums[i]-m);
        }
        long long p= nums[0]+u;
        return p<=m;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int l = 0;
        int r = INT_MIN;
        for(auto c:nums)r = max(c,r);
        int ans =r;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(check(m,nums))
                r = m-1,ans = m;
            else l = m+1;
        }
        return ans;
    }
};
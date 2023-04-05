class Solution {
public:
    bool check(int m,vector<int>&nums)
    {
        vector<long long>v(nums.begin(),nums.end());
        for(int i = nums.size()-1;i>=1;--i)
        {
            if(v[i]<=m)continue;
            v[i-1]+=(v[i]-m);
        }
       
        return v[0]<=m;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int l = 0;
        int r = 1e9;
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
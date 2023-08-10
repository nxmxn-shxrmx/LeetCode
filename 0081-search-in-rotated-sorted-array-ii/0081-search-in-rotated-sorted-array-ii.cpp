class Solution {
public:
    bool search(vector<int>& nums, int t) {
        int l = 0;
        int r = nums.size()-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            cout<<m<<" ";
            if(nums[m]==t)return 1;
            if(nums[m]==nums[l])l++;
            else if(nums[l]<nums[m])
            {
                if(nums[l]>t || nums[m]<t)l = m+1;
                else r = m-1;
            }
            else
            {
                if(nums[l]<=t || nums[m]>t)r=m-1;
                else l = m+1;
            }
            
        }
        return 0;
    }
};
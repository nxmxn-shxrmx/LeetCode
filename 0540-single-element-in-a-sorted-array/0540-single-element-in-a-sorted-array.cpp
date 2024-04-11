class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums.back()!=nums[nums.size()-2])return nums.back();
        int l = 1;
        int r = nums.size()-2;
        
        while(l<=r)
        {
            int m = (l+r)/2;
            
            if(nums[m]!=nums[m-1]&&nums[m]!=nums[m+1])return nums[m];
            
            if((m%2&&nums[m]==nums[m-1])||(m%2==0&&nums[m]==nums[m+1]))l = m+1;
            else r = m-1;
        }
        return -1;
    }
};
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums.back()!=nums[nums.size()-1])return nums.back();
        if(nums[0]!=nums[1])return nums[0];
        int l = 0;
        int r = nums.size()-1;
        while(l<=r)
        {
            int m= (l+r)/2;
            if(nums[m]==nums[m+1])
                m++;
            if(nums[m]!=nums[m-1])return nums[m];
            if((r-m)%2==1)
                l = m+1;
            else if((m-l)%2==0)
                r = m -2;
        }
        return -1;
    }
};
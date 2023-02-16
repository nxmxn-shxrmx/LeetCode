class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums.size()!=1&&nums[0]!=nums[1])return nums[0];
        if(nums.size()!=1&&nums[nums.size()-1]!=nums[nums.size()-2])return nums.back();
        int l = 0;
        int r = nums.size()-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(nums[m]!=nums[m-1]&&nums[m]!=nums[m+1])return nums[m];
            
            if(nums[m]==nums[m-1])
            {
                if((r-m)%2==0)
                    r = m-2;
                else l = m+1;
            }
            else 
            {
                if((m-l)%2==0)
                    l = m+2;
                else r = m-1;
            }
           
        }
        return nums[0];
    }
};
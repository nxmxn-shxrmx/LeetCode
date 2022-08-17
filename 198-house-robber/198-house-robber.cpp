class Solution {
public:
    int rob(vector<int>& nums) {
        long long a=0,b=0;
        for(int i = 0;i<nums.size();++i)
        {
            if(i&1)
            {
                a = max(nums[i]+a,b);
            }
            else
            {
                b =max(nums[i]+b,a);
            }
        }
        return max(a,b);
    }
};
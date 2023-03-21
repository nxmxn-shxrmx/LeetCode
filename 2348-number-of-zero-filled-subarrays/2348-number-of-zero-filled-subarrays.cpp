class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        for(int i = 0;i<nums.size();++i)
        {
            if(nums[i]!=0)continue;
            int j = i;
            while(i<nums.size() && nums[i]==0)
                ans+=(i-j+1),++i;
        }
        return ans;
    }
};
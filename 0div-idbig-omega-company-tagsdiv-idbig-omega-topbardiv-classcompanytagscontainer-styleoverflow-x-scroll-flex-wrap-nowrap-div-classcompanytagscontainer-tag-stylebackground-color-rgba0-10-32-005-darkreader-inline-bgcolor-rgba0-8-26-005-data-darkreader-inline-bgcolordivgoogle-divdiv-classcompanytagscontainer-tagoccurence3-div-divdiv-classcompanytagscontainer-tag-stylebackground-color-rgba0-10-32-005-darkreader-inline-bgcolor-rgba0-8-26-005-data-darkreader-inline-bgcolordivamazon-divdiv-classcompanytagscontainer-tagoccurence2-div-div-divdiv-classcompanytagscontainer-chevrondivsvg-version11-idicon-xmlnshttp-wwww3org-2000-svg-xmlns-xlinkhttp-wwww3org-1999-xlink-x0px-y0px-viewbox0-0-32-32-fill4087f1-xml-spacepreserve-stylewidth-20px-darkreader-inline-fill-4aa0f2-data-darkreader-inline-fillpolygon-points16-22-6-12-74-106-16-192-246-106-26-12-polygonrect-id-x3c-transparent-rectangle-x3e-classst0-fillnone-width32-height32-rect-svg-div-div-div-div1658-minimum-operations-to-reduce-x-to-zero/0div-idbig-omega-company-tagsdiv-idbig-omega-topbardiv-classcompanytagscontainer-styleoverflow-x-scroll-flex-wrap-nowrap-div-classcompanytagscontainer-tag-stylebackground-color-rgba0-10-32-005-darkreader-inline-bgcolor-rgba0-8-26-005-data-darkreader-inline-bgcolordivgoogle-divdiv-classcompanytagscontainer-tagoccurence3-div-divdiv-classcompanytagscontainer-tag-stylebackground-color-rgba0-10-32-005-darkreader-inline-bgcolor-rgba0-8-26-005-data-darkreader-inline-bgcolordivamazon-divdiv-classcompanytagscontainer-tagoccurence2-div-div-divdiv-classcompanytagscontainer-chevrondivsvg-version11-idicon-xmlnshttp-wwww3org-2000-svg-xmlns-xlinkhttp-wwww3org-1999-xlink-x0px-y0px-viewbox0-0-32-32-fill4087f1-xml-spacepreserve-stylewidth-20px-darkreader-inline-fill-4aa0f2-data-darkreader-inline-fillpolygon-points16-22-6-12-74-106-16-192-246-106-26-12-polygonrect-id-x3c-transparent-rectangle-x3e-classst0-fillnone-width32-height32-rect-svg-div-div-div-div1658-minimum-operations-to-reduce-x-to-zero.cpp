class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if(nums.back()>x && nums[0]>x)return -1;
        
        long long sum = 0;
        for(auto c:nums)sum+=c;
        
        if(sum<x)return -1;
        
        sum-=x;
        
        int cur = 0;
        int ans = INT_MIN;
        for(int i = 0,j =0;j<nums.size();)
        {
            if(cur+nums[j]==sum)
            {
                cur+=nums[j];
                ans = max(ans,j-i+1);
                j++;
            }
            else if(cur+nums[j]>sum)
            {
                if(i<=j)
                cur-=nums[i++];
                
                else j++;
            }
            else cur+=nums[j++];
        }
        return ans ==INT_MIN?-1:nums.size()-ans;
    }
};
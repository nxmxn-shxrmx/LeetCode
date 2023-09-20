class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if(nums.back()>x && nums[0]>x)return -1;
        
        long long sum = 0;
        for(auto c:nums)sum+=c;
        
        if(sum<x)return -1;
        
        sum-=x;
        
        
        int ans = INT_MIN;
        for(int i = 0,j =0;j<nums.size();++j)
        {
            sum-=nums[j];
            while(i<=j && sum<0)
                sum+=nums[i++];
            if(sum==0)ans = max(ans,j+1-i);
        }
        return ans ==INT_MIN?-1:nums.size()-ans;
    }
};
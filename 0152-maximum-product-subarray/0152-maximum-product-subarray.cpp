class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int las = 1;
        int cur = 1;
        int ans = INT_MIN;
        for(int i = 0;i<nums.size();++i)
        {
            if(las==0)las = 1;
            if(cur==0)cur = 1;
            
            las*=nums[i];
            cur*=nums[nums.size()-1-i];
            
            ans= max(ans,max(las,cur));
        }
        return ans;
    }
};
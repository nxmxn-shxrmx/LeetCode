class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sum = 0;
        long long g = 0;
        for(auto c:nums)
            sum+=c;
        
        int c = 0;
        
        int a = INT_MAX;
        for(int i = 0;i<nums.size();++i)
        {
            g+=nums[i];
            sum-=nums[i];
            long long p = (g/(i+1));
            
            long long h = 0;
            if(nums.size()-1!=i)
                h = sum/(nums.size()-1-i);
            
            p = abs(p-h);
            if(a>p)
            {
                a = p;
                c= i;
            }
        }
        return c;
    }
};
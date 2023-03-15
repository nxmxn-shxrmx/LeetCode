class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ct = 0;
        nums.push_back(INT_MAX);
        long long p = 1;
        for(int i = 0;i<nums.size() && p<n;++i)
        {
            while(nums[i]>p && p<=n)
            {
                p+=p;
                ct++;
            }
            p+=nums[i];
        }
        return ct;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long su = 0;
        for(int i = 0;i<nums.size();++i)
        {
            su = su^i^nums[i];
        }
        return su^nums.size();
    }
};
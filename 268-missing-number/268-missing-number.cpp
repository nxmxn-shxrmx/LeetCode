class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long su = 0;
        for(auto c:nums)
            su+=c;
        long long n = nums.size();
        n = n*(n+1)/2;
        return n-su;
    }
};
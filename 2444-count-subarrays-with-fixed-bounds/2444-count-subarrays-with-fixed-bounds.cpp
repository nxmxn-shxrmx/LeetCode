class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        bool minF = false, maxF = false;
        int l = 0, ml = 0, mxl = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num < minK || num > maxK) {
                minF = false;
                maxF = false;
                l = i+1;
            }
            if (num == minK) {
                minF = true;
                ml = i;
            }
            if (num == maxK) {
                maxF = true;
                mxl = i;
            }
            if (minF && maxF) {
                ans += (min(ml, mxl)- l + 1);
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int next = 0;
        for(int i = 0;i<nums.size();++i)
        {
            if(i<=next)
                next = max(next,i+nums[i]);
            else return 0;
        }
        return 1;
    }
};
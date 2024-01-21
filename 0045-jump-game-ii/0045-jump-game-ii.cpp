class Solution {
public:
    int jump(vector<int>& nums) {
        int next = 0;
        int atmost = 0;
        int mini_jump =0;
        for(int i = 0;i<nums.size()-1;++i)
        {
            atmost = max(i+nums[i],atmost);
            if(next==i)
            {
                next=atmost;
                mini_jump++;
            }
        }
        return mini_jump;
    }
};
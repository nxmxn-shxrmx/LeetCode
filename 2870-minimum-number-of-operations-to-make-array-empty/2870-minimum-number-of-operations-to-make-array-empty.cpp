class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count  = 0;
        for(int i = 0;i<nums.size();)
        {
            int j=i;
            while(j+1<nums.size()&&nums[j]==nums[j+1])
                ++j;
            int ct = j-i+1;
            if(ct!=1)
            {
                count+=(ct+2)/3;
            }
            else
                return -1;
            i=j+1;
        }
        
        return  count;
    }
};
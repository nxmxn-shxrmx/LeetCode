class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0)
            return 0;
        
        int x = 0;
        int s = 1;
        int o = 0;
        for(int i =0;i<nums.size();++i)
        {
            s*=nums[i];
            while(k<=s && o<=i)
            {
                s/=nums[o];
                ++o;
            }
            
            x += i-o+1;
        }
        return x;
    }
};
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int b = 0;
        int c = 0;
        for(int i = 0;i<nums.size();++i)
        {
            if(i-k>=0 && nums[i-k]==-1)
                b = !b;
            
            if(b==nums[i])
            {
                b = !b;
                nums[i]=-1;
                c++;
            
                if(k+i>nums.size())
                {
                    // cout<<c<<"\n";
                    return -1;
                }
            }
        }
        return c;
        
    }
};
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int b = 0;
        set<int>p;
        int c = 0;
        for(int i = 0;i<nums.size();++i)
        {
            if(p.find(i)!=p.end())
                b = !b;
            if(b==nums[i])
            {
                b = !b;
                p.insert(k+i);
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
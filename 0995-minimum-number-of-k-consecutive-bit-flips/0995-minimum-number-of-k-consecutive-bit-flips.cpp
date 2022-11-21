class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int b = 0;
        queue<int>q;
        int c = 0;
        for(int i = 0;i<nums.size();++i)
        {
            if(!q.empty()&&q.front()==i)
                b = !b,q.pop();
            
            if(b==nums[i])
            {
                b = !b;
                q.push(i+k);
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
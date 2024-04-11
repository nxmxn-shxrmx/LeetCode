class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int las = 1;
        int cur = 1;
        int ans = INT_MIN;
        for(auto c:nums)
        {
            if(c<0)
            {
                cur*=las*c;
                ans = max(ans,cur);
                if(cur<0)
                {
                    las = cur;
                    cur = 1;
                    
                }
                else
                las =1;
            }
            else if(c==0)
            {
                las=1;
                cur=1;
                ans = max(ans,0);
            }
            else
            {
                cur*=c;
                ans = max(ans,cur);
            }
        }
        reverse(nums.begin(),nums.end());
          las = 1;
        cur = 1;
    
        for(auto c:nums)
        {
            if(c<0)
            {
                cur*=las*c;
                ans = max(ans,cur);
                if(cur<0)
                {
                    las = cur;
                    cur = 1;
                    
                }
                else
                las =1;
            }
            else if(c==0)
            {
                las=1;
                cur=1;
                ans = max(ans,0);
            }
            else
            {
                cur*=c;
                ans = max(ans,cur);
            }
        }
        return ans;
    }
};
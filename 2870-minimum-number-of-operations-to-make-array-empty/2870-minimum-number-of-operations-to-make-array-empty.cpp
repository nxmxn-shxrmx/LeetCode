class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int>count;
        int ans=0;
        for(auto c:nums)count[c]++;
        for(auto c:count)
        {
            int ct = c.second;
            if(ct!=1)
                ans+=(ct+2)/3;
            else
                return -1;
        }
        
        return  ans;
    }
};
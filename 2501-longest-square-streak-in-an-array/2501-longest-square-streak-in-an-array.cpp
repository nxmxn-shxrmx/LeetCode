class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        long long t= 0;
        multiset<int>s(nums.begin(),nums.end());
        while(s.size()!=0)
        {
            long long u =1;
            
            auto it = s.begin();
            long long p = *it;
            
            s.erase(s.find(*it));
            while(s.find(p*p)!=s.end())
            {
                u++;
                p = p*p;
                s.erase(s.find(p));
            }
          t=  max(t,u);
        }
        if(t==1)
            return -1;
        return t;
    
    }
};
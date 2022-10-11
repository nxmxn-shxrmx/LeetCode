class Solution {
public:
    int lis(vector<int>v)
    {
        vector<int>s;
        for(auto c:v)
        {
            if(s.size()>2)
                return 3;
            auto it = lower_bound(s.begin(),s.end(),c);
            if(it==s.end())
                s.push_back(c);
            else
                *it = c;
        }
        return s.size();
    }
    bool increasingTriplet(vector<int>& nums) {
        
        if(nums.size()<=2)
            return false;
        
        return lis(nums)>2;
    }
};
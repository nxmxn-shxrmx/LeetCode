class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,long long>m;
        for(int i = 0;i<size(nums);++i)
            m[nums[i]-i]++;
        
    long long k = nums.size()-1;
    long long l = k*(k+1)/2;
        for(auto c:m)
        {
            long long p = c.second-1;
            p = p*(p+1)/2;
            l-=p;
            
        }
        return l;
    }
};
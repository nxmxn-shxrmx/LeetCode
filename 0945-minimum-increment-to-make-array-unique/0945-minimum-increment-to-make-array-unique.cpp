class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        set<int>s;
        sort(nums.begin(),nums.end());
        for(int i = 1;i<=nums[nums.size()-1];++i)s.insert(i);
        for(int i =0;i<nums.size();++i)
        {
            if(i-1>=0 && nums[i]==nums[i-1])
                continue;
            s.erase(nums[i]);
        }
        int sum = 0;
        int u = nums[nums.size()-1]+1;
        
        for(int i = 0;i<nums.size();++i)
        {
            if(i-1>=0 && nums[i]==nums[i-1])
            {
                if(s.size()==0)
                {
                    sum += u-nums[i];
                    u++;
                }
                else
                {
                    auto it = s.upper_bound(nums[i]);
                    if(it!=s.end())
                    {
                        sum+=*it-nums[i];
                        s.erase(*it);
                    }
                    else
                    {
                        s.clear();
                        sum+=u-nums[i];
                        u++;
                    }
                }
            }
        }
        return sum;
    }
};
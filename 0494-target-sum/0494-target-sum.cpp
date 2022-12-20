class Solution {
public:
    map<pair<int,int>,int>m;
    int f(int i,vector<int>v,int sum)
    {
        if(i==v.size())
        {
            if(sum==0)
                return 1;
            return 0;
        }
        if(m.find({i,sum})!=m.end())
            return m[{i,sum}];
        
       return m[{i,sum}]=f(i+1,v,sum-v[i])+f(i+1,v,sum+v[i]);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return f(0,nums,target);
    }
};
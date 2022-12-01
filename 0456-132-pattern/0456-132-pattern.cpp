class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size()<=2)
            return 0;
        
        vector<int>m(nums.size());
        m[0]=nums[0];
        for(int i =1;i<nums.size();++i)
            m[i] = min(m[i-1],nums[i]);
        stack<int>s;
        for(int i= nums.size()-1;i>=1;--i)
        {
            while(!s.empty() && s.top()<=m[i])
                s.pop();
            
            if(s.size())
            {
                if(m[i]<nums[i] && nums[i]>s.top())
                    return 1;
            }              
            
                s.push(nums[i]);
        }
        return 0;
    }
};
/*
-1 -1 -1 -1
       0
 
*/
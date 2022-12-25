class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>v;
        for(auto c:queries)
        {
            priority_queue<int>q;
            long long u = 0;
            for(auto x:nums)
            {
                if(x+u<=c)
                {
                    u+=x;
                    q.push(x);
                }
                else if(!q.empty())
                {
                    if(q.top()>x)
                    {
                        u-=q.top();
                        q.pop();
                        q.push(x);
                        u+=x;
                    }
                }
            }
            v.push_back(q.size());
        }
        return v;
    }
};
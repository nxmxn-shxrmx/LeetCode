class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>v(queries.size());
        vector<vector<int>>p;
        for(int i = 0;i<queries.size();++i)
            p.push_back({queries[i],i});
        sort(p.begin(),p.end());
        long long u = 0;
        priority_queue<int>q;
        for(auto c:nums)
        {
            if(u+c<=p[p.size()-1][0])
            {
                q.push(c);
                u+=c;
            }
            else if(!q.empty() && q.top()>c)
            {
                u-=q.top();
                u+=c;
                q.pop();
                q.push(c);
            }
        }
        
        for(int i =p.size()-1;~i;--i)
        {
            while(u>p[i][0] && !q.empty())
            {
                u-=q.top();
                q.pop();
            }
            v[p[i][1]]=q.size();
        }
        return v;
    }
};
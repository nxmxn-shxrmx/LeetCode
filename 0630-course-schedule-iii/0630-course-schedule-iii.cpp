class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        vector<pair<int,int>>v;
        int mx = 0;
        priority_queue<int>q;
        for(auto c:courses)
            if(c[0]<=c[1])
            v.push_back({c[1],c[0]});
        sort(v.begin(),v.end());
        long long t = 0;
        for(auto c:v)
        {
            int de = c.first;
            int du = c.second;
            if(t+du<=de)
            {
                t+=du;
                q.push(du);
            }
            else if(!q.empty() && q.top()>=du)
            {
                while(!q.empty() && q.top()>=du && (t+du>de))
                {
                    t-=q.top();
                    q.pop();
                }
                if(t+du<=de)
                {
                    t+=du;
                    q.push(du);
                }
            }
        }
        return  q.size();
        
    }
};
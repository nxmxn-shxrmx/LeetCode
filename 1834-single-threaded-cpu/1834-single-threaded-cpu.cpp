class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& task) {
      
        priority_queue<vector<int>>q;
        priority_queue<vector<int>>p;
        for(int i =0;i<task.size();++i)
            q.push({-task[i][0],-task[i][1],-i});
        vector<int>v;
        int  t = -q.top()[0];
        while(!q.empty())
        {
            while(!q.empty() && -q.top()[0]<=t)
            {
                p.push({q.top()[1],q.top()[2]});
                q.pop();
            }
            if(p.empty())
            {
                t  = -q.top()[0];
                while(!q.empty() && -q.top()[0]<=t)
                {
                    p.push({q.top()[1],q.top()[2]});
                    q.pop();
                }
            }
            t+=(-p.top()[0]);
            v.push_back(-p.top()[1]);
            p.pop();
    
        }
        while(!p.empty())
        {
            v.push_back(-p.top()[1]);
            p.pop();
        }
        return v;
    }
};
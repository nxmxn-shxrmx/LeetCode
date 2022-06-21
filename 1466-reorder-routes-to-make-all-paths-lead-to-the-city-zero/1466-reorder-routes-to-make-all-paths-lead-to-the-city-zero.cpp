class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>v(n);
        vector<bool>b(n);
        queue<int>q;
        for(auto c:connections)
        {
            v[c[0]].push_back({c[1],0});
            v[c[1]].push_back({c[0],1});
        }
        q.push(0);
        b[0]=true;
        int c= 0;
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            for(auto x:v[t])
            {
               
                if(!b[x.first])
                {
                    if(x.second==0)
                        c++;
                    b[x.first]=true;
                    q.push(x.first);
                }
            }
        }
        return c;
    }
};
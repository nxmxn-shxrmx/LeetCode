class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        vector<int>col(g.size());
        vector<bool>b(g.size());
        
        for(int i = 0;i<g.size();++i)
        {
            if(!b[i])
            {
                col[i]=1;
                queue<int>q;
                q.push(i);
                while(!q.empty())
                {
                    int i=q.front();
                    q.pop();
                    if(b[i])
                        continue;
                    b[i]=true;
                    
                    for(auto c:g[i])
                    {
                        if(col[i]==col[c])
                            return false;
                        
                        if(col[i]==1)
                            col[c]=2;
                        else
                            col[c]=1;
                        q.push(c);
                    }
                }
            }
        }
        return true;
    }
};
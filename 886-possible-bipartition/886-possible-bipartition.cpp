class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        vector<vector<int>>v(n+1);
        for(auto c:d)
        {
            v[c[0]].push_back(c[1]);
            v[c[1]].push_back(c[0]);
        }
        
        vector<int>col(n+1);
        vector<bool>b(n+1);
        for(int i = 1;i<=n;++i)
        {
            if(!b[i])
            {
                col[i]=1;
                queue<int>q;
                q.push(i);
                while(!q.empty())
                {
                    int i = q.front();
                    q.pop();
                    if(b[i])
                        continue;
                    b[i]=true;
                    
                    for(auto c:v[i])
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
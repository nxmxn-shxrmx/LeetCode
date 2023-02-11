class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
     vector<vector<int>>blueG(n);
     vector<vector<int>>redG(n);
     for(auto c:blueEdges)
            blueG[c[0]].push_back(c[1]);
     for(auto c:redEdges)
            redG[c[0]].push_back(c[1]);
      
    vector<int>ans(n,-1);
    ans[0] = 0;
    vector<bool>visR(n),visB(n);
    queue<pair<int,int>>q;
    q.push({0,0});
    int ct = 0;
    while(!q.empty())
    {
        int sz = q.size();
        while(sz--)
        {
            auto it = q.front();
            q.pop();
            if(it.first==0)
            {
                for(auto c:blueG[it.second])
                {
                    if(!visR[c])
                    {
                        if(ans[c]==-1)ans[c]=INT_MAX;
                        ans[c] = min(ans[c],ct+1);
                        q.push({2,c});
                    }
                }
                for(auto c:redG[it.second])
                {
                    if(!visB[c])
                    {
                        if(ans[c]==-1)ans[c]=INT_MAX;
                        ans[c] = min(ans[c],ct+1);
                        q.push({1,c});
                    }
                }
            }
            else if(it.first==1)
            {
                visR[it.second]=1;
                for(auto c:blueG[it.second])
                {
                    if(!visB[c])
                    {
                        if(ans[c]==-1)ans[c]=INT_MAX;
                        ans[c] = min(ans[c],ct+1);
                        q.push({2,c});
                    }
                }
            }
            else
            {
                visB[it.second]=1;
                for(auto c:redG[it.second])
                {
                    if(!visR[c])
                    {
                        if(ans[c]==-1)ans[c]=INT_MAX;
                        ans[c] = min(ans[c],ct+1);
                        q.push({1,c});
                    }
                }
            }
        }
        ct++;
    }
    return ans;
    }
};
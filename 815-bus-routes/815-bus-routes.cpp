class Solution {
public:
    
    unordered_map<int,set<int>>m;
    unordered_map<int,bool>v;
    int numBusesToDestination(vector<vector<int>>& r, int s, int t) {
        
        for(int i = 0;i<r.size();++i)
        {
            for(auto c:r[i])
            m[c].insert(i);
        }
        
        
        queue<int>q;
        q.push(s);
        int sq = 1;
        while(!q.empty())
        {
            int sz= q.size();
            while(sz--)
            {
                int p = q.front();
                if(p==t)
                    return sq-1;
                q.pop();
                for(auto c:m[p])
                {
                    if(!v[c])
                    {
                        v[c]=true;
                        for(auto u:r[c])
                        {
                            q.push(u);
                        }
                    }
                }
            }
             sq++;  
        }
            
            return -1;
    }
};
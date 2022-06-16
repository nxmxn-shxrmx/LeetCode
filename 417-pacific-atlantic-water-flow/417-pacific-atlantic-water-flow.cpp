class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        map<pair<int,int>,bool>m,n;
        queue<pair<int,int>>q;
        for(int i = 0;i<h.size();++i)
            m[{i,0}]=true,q.push({i,0});
        for(int i=0;i<h[0].size();++i)
            m[{0,i}]=true,q.push({0,i});
        
        while(!q.empty())
        {
            int i =q.front().first;
            int j = q.front().second;
            
            if(i+1<h.size() && h[i+1][j]>=h[i][j])
            {
                if(m[{i+1,j}]==false)
                {
                    m[{i+1,j}]=true;
                    q.push({i+1,j});
                }
            }
            if(i-1>=0 && h[i-1][j]>=h[i][j])
            {
                if(m[{i-1,j}]==false)
                {
                    m[{i-1,j}]=true;
                    q.push({i-1,j});
                }
                
            }
             if(j-1>=0 && h[i][j-1]>=h[i][j])
            {
                if(m[{i,j-1}]==false)
                {
                    m[{i,j-1}]=true;
                    q.push({i,j-1});
                }
                
            }
             if(j+1<h[0].size() && h[i][j+1]>=h[i][j])
            {
                if(m[{i,j+1}]==false)
                {
                    m[{i,j+1}]=true;
                    q.push({i,j+1});
                }
                
            }
            q.pop();
        }
        
        
         for(int i = 0;i<h.size();++i)
            n[{i,h[0].size()-1}]=true,q.push({i,h[0].size()-1});
        for(int i=0;i<h[0].size();++i)
            n[{h.size()-1,i}]=true,q.push({h.size()-1,i});
        
        while(!q.empty())
        {
            int i =q.front().first;
            int j = q.front().second;
            
            if(i+1<h.size() && h[i+1][j]>=h[i][j])
            {
                if(n[{i+1,j}]==false)
                {
                    n[{i+1,j}]=true;
                    q.push({i+1,j});
                }
            }
            if(i-1>=0 && h[i-1][j]>=h[i][j])
            {
                if(n[{i-1,j}]==false)
                {
                    n[{i-1,j}]=true;
                    q.push({i-1,j});
                }
                
            }
             if(j-1>=0 && h[i][j-1]>=h[i][j])
            {
                if(n[{i,j-1}]==false)
                {
                    n[{i,j-1}]=true;
                    q.push({i,j-1});
                }
                
            }
             if(j+1<h[0].size() && h[i][j+1]>=h[i][j])
            {
                if(n[{i,j+1}]==false)
                {
                    n[{i,j+1}]=true;
                    q.push({i,j+1});
                }
                
            }
            q.pop();
        }
         
        vector<vector<int>>v;
    for(auto c:m)
    {
        if(n[c.first])
            v.push_back({c.first.first,c.first.second});
    }
      return v;
        
    }
};
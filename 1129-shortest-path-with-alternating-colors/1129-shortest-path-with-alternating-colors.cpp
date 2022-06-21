class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        
        
        vector<vector<int>>r(n),b(n);
        queue<pair<int,int>>q;
        map<pair<int,int>,bool>m;
        for(auto c: red)
            r[c[0]].push_back(c[1]);
        for(auto c: blue)
            b[c[0]].push_back(c[1]);
    
        
        vector<int>h(n,INT_MAX);
        h[0]= 0;
        for(auto c:r[0])
        {
            if(h[c]>h[0]+1)
                h[c]=h[0]+1;
               
            if(!m[{c,0}])
            q.push({c,0}),m[{c,0}]=true;
        }
        for(auto c:b[0])
        {
             if(h[c]>h[0]+1)
                h[c]=h[0]+1;
             
        
                if(!m[{c,1}])
                q.push({c,1}),m[{c,1}]=true;
    
    
        }
        int st =2;
        while(!q.empty())
        {
            int si = q.size();
            
            while(si--)
            {
                int i = q.front().first;
                int t = q.front().second;
                q.pop();

                if(t==0)
                {
                
                    for(auto c:b[i])
                    {
                        if(h[c]>st)
                            h[c]=st;
            
                        if(m[{c,1}]==false)
                        q.push({c,1}),m[{c,1}]=true;
                    
                    }
                }
                else 
                {
                
                    for(auto c:r[i])
                    {
                   // cout<<t<<" "<<0<<" "<<c<<" "<<i<<"\n";
                        if(h[c]>st)
                            h[c]=st;
            
                        if(m[{c,0}]==false)
                        q.push({c,0}),m[{c,0}]=true;
                    
    
                    }
                }
            }
            
            st++;
        
        }
        for(int i = 0;i<n;++i)
            if(h[i]==INT_MAX)
                h[i]=-1;
     return h;   
    }
};
class Solution {
public:
     int ans = -1;
    void dfs(int c,vector<int>&edges,int i,vector<int>&pos,vector<int>&b)
    {
        
        if(c==-1 || b[c])return;
        
        if(pos[c]!=-1)
        {
            ans = max(i-pos[c],ans);
            return;
        }
        pos[c]=i;
        dfs(edges[c],edges,i+1,pos,b);
        b[c]=1;
        
    }
    int longestCycle(vector<int>& edges) {

        
        queue<int>q;
        vector<int>b(edges.size());
        vector<int>in(edges.size());
        for(auto c:edges)
        {
            if(c==-1)continue;
            in[c]++;
        }
        for(int i =0;i<in.size();++i)
        {
            if(in[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int i = q.front();
            b[i]=1;
            q.pop();
            if(edges[i]==-1)continue;
            in[edges[i]]--;
            if(in[edges[i]]==0)q.push(edges[i]);
            edges[i]=-1;            
        }
        
        // vector<int>pos(edges.size(),-1);

        for(int i = 0;i<edges.size();++i)
        {
            if(!b[i])
            {
                int c = 1;
                b[i]=1;
                int p = edges[i];
                while(!b[p])
                {
                    b[p]=1;
                    p = edges[p];
                    c++;
                }
                ans = max(c,ans);
            }
                
        }
        
        return ans;
    }
};
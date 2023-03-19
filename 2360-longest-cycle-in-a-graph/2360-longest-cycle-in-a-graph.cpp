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
        vector<int>pos(edges.size(),-1);
        vector<int>b(edges.size());
    
        for(int i = 0;i<edges.size();++i)
        {
            if(!b[i])
            {
                pos[i]=0;
                dfs(edges[i],edges,1,pos,b);
                b[i]=1;
            }
                
        }
        return ans;
    }
};
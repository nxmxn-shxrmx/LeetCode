// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
     void dfs(int i,int &t,vector<vector<int>>&v,vector<int>&di,vector<int>&lo,int pre,set<int>&s)
    {
        lo[i]=t;
        di[i]=t++;
        
        for(auto c:v[i])
        {
            if(pre==c)
            continue;
            
            if(di[c]==-1)
            {
                dfs(c,t,v,di,lo,i,s);
                
                if(pre!=-1 && lo[c]>=di[i])
                s.insert(i);
                
            }
            else if(pre!=-1)
              lo[i] =min(lo[i],di[c]);
        }
        
    }
    int doctorStrange(int N, int M, vector<vector<int>> & g)
    {
         vector<vector<int>>v(N);
         for(int i = 0;i<M;++i)
         {
             v[g[i][0]-1].push_back(g[i][1]-1);
             v[g[i][1]-1].push_back(g[i][0]-1);
         }
         vector<int>di(N,-1);
         vector<int>lo(N);
         set<int>s;
         int t=0;
         for(int i = 0;i<N;++i)
         {
             if(di[i]==-1)
            dfs(i,t,v,di,lo,-1,s);
         }
         
         return s.size();

    }
};


// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,i;
        cin>>n>>m;
        vector<vector<int>> g(n+1);
        for(i=0;i<m;i++)
        {
            int a,b;cin>>a>>b;
            g[i].push_back(a);
            g[i].push_back(b);
        }
        Solution ob;
        int ans = ob.doctorStrange(n, m, g);
        cout<<ans<<endl;
    }
	return 0;
}  // } Driver Code Ends
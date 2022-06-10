// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int minu(vector<bool>&vis,vector<int>&k)
	{
	    int p = INT_MAX, ind;
	    for(int i = 0;i<k.size();++i)
	    {
	        if(p>k[i] && !vis[i])
	        {
	            p  = k[i];
	            ind = i;
	        }
	    }
	    return ind;
	    
	}
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<int>parent(n);
        parent[0]=-1;
        vector<bool>vis(n);
        vector<int>k(n,INT_MAX);
        k[0]=0;
        
        for(int i = 0;i<n-1;++i)
        {
            int u = minu(vis,k);
            
            vis[u]=true;
            
            for(int j = 0;j<adj[u].size();++j)
            {
                // cout<<adj[u][j][0]<<" "<<adj[u][j][1]<<"\n";
                if(!vis[adj[u][j][0]] && adj[u][j][1]<k[adj[u][j][0]])
                {

                    k[adj[u][j][0]]=adj[u][j][1];
                    parent[adj[u][j][0]] = u;
                }
            }
    
        }
        int x = 0;        
      for(auto c:k)
      x+=c;
        return x;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int mini(vector<int>&k ,vector<bool>&vis)
    {
        int id = INT_MAX,in=-1;
        for(int i = 0;i<k.size();++i)
        {
            if(k[i]<=id && !vis[i])
            {
                id = k[i];
                in = i;
            }
        }
        return in;
    }
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>k(n,INT_MAX);
        k[S]=0;
        vector<bool>vis(n,false);
        
        for(int i = 0;i<n-1;++i)
        {
            int u = mini(k,vis);
         
            vis[u]=true;
            for(int j = 0;j<adj[u].size();++j)
            {
                if(u!=INT_MAX && !vis[adj[u][j][0]] && k[u]!=INT_MAX && k[u]+adj[u][j][1]<k[adj[u][j][0]])
                k[adj[u][j][0]]=k[u]+adj[u][j][1];
            }
            
        }
        return k;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
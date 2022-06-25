// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	vector<int>od;
	void dfs(int i,vector<int>adj[],vector<bool>&b,int t=0)
	{
	    b[i]=true;
	    for(auto c:adj[i])
	        if(!b[c])
	            dfs(c,adj,b,t);
	   if(t==0)
	   od.push_back(i);
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int>g[V];
        for(int i = 0;i<V;++i)
        {
            for(auto c:adj[i])
                g[c].push_back(i);
        }
        vector<bool>b(V);
        for(int i=0;i<V;++i)
        if(!b[i])
        dfs(i,adj,b);
        int c= 0;
        vector<bool>b2(V);
        for(int i =V-1;~i;--i)
        {
            if(!b2[od[i]])
            {
                c++;
                dfs(od[i],g,b2,1);
            }
        }
        return c;
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
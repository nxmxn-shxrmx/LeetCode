// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    int dfs(int i,vector<int>adj[],vector<bool>&b)
    {
        b[i]=true;
        int c= 0;
        for(auto x:adj[i])
        {
            if(!b[x])
                c+=dfs(x,adj,b);
        }
        
        return c+1;
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    for(int i = 0;i<V;++i)
	    {
	        vector<bool>b(V);
	        int j = dfs(i,adj,b);
	        if(j==V)
	        return i;
	    }
	    return -1;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
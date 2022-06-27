// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
  
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int S)
    {
        queue<int>q;
        vector<int>k(n,INT_MAX);
        k[S]=0;
        q.push(S);
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            
            for(auto c:adj[i])
            {
                if(k[i]+c[1]<k[c[0]])
                {
                    q.push(c[0]);
                    k[c[0]] = k[i]+c[1];
                }
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
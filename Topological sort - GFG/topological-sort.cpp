// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
// 	vector<bool>b;
// 	stack<int>s;
// 	void dfs(int i,vector<int>adj[])
// 	{
// 	    b[i]=true;
// 	    for(auto c:adj[i])
// 	    {
// 	        if(!b[c])
// 	        dfs(c,adj);
// 	    }
// 	    s.push(i);
// 	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   // b.clear();
	   // b = vector<bool>(V);
	   // for(int i = 0;i<V;++i)
	   // {
	   //     if(!b[i])
	   //     {
	   //         dfs(i,adj);
	   //     }
	   // }
	   // vector<int>g;
	   // while(!s.empty())
	   // {
	   //     g.push_back(s.top());
	   //     s.pop();
	   // }
	   // return g;
	    vector<int>v;
	    
	    vector<int>m(V);
	    
	    for(int i =0;i<V;++i)
	        for(auto x:adj[i])
	            m[x]++;
	            
	   queue<int>q;
	   for(int i = 0;i<V;++i)
	   {
	       if(m[i]==0)
	       q.push(i);
	   }
	   while(!q.empty())
	   {
	       int i = q.front();
	       q.pop();
	       v.push_back(i);
	   
	       
	       for(auto c:adj[i])
	       {
	           m[c]--;
	           if(m[c]==0)
	           {
	               q.push(c);
	           }
	       }
	   }
	   return v;
	   
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
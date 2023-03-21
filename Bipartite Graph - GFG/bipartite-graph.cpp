//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>col(V,-1);
	
	    for(int i = 0;i<V;++i)
	    {
	        if(col[i]==-1)
	        {
	           queue<int>q;
	           q.push(i);
	           col[i]=0;
	           while(!q.empty())
	           {
	               int i = q.front();
	               q.pop();
	               for(auto c:adj[i])
	               {
	                   if(col[c]==-1)
	                   {
	                       col[c] = !col[i];
	                       q.push(c);
	                   }
	                   else if(col[i]==col[c])return 0;
	               }
	           }
	        }
	    }
	    return 1;
	}

};

//{ Driver Code Starts.
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
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        vector<int>ind(V);
        vector<vector<int>>v(V);
        for(int i = 0;i<V;++i)
        {
            for(auto c:adj[i])
            {
                ind[i]++;
                v[c].push_back(i);
            }
        }
        queue<int>q;
        for(int i = 0;i<V;++i)
        {
            if(ind[i]==0)
                q.push(i);
        }
        
        vector<int>ans;
        while(!q.empty())
        {
            int i = q.front();
            ans.push_back(i);
            q.pop();
            for(auto c:v[i])
            {
                ind[c]--;
                if(ind[c]==0)
                    q.push(c);
            }
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
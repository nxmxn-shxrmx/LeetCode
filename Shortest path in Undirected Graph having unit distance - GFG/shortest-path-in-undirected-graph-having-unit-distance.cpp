//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
          vector<int>dis(N,-1);
        vector<vector<int>>v(N);
        for(auto c:edges)
            v[c[0]].push_back(c[1]),v[c[1]].push_back(c[0]);
        
        queue<int>q;
        q.push(src);
        dis[src]=0;
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            for(auto c:v[i])
            {
                if(dis[c]==-1 || (dis[i]+1<=(dis[c])))
                    {
                        dis[c]= (dis[i]+1);
                        q.push(c);
                    }
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
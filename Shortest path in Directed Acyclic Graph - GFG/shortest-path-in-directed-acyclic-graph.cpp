//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int>dis(N,-1);
        vector<vector<pair<int,int>>>v(N);
        for(auto c:edges)
            v[c[0]].push_back({c[1],c[2]});
        
        queue<int>q;
        q.push(0);
        dis[0]=0;
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            for(auto c:v[i])
            {
                if(dis[c.first]==-1 || (dis[i]+c.second<=(dis[c.first])))
                    {
                        dis[c.first]= (dis[i]+c.second);
                        q.push(c.first);
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  #define ll long long
  ll ans = 0;
  ll mod = 1e9+7;
  void f(ll n,vector<vector<ll>>&pr)
  {
      if(n==-1)
      {
          ans = (ans+1)%mod;
          return;
      }
      for(auto c:pr[n])
      f(c,pr);
  }
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        ans = 0;
        vector<ll>dis(n,INT_MAX);
        dis[0]=0;
        vector<vector<pair<ll,ll>>>v(n);
        for(auto c:roads)
        {
            v[c[0]].push_back({c[1],c[2]});
            v[c[1]].push_back({c[0],c[2]});
        }
        priority_queue<pair<ll,ll>>q;
        q.push({0,0});
        vector<vector<ll>>pr(n);
        pr[0] = {-1};
        
        while(!q.empty())
        {
            ll s = abs(q.top().first);
            ll i = q.top().second;
            q.pop();
            if(i==n-1)
            {
            
                continue;
            }
            for(auto c:v[i])
            {
                if(dis[c.first]>(dis[i]+c.second))
                {
                    pr[c.first].clear();
                    pr[c.first].push_back(i);
                    dis[c.first]=dis[i]+c.second;
                    q.push({-dis[c.first],c.first});
                }
                else if(dis[c.first]==dis[i]+c.second)
                {
                    pr[c.first].push_back(i);
                }
            }
            
        }
        f(n-1,pr);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends
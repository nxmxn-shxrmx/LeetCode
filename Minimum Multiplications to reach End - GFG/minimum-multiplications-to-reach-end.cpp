//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int s, int e) {
        // code here
        vector<int>dis(100001,INT_MAX);
        queue<pair<int,int>>q;
        dis[s]=0;
        q.push({0,s});
        int mod = 100000;
        while(!q.empty())
        {
            int p = abs(q.front().first);
            int i= q.front().second;
            q.pop();
            if(i==e)return p;
            for(auto c:arr)
            {
                int u = (c*i)%mod;
                if(dis[u]>dis[i]+1)
                {
                    dis[u] = dis[i]+1;
                    q.push({-dis[u],u});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
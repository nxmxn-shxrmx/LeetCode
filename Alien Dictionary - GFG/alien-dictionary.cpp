//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string d[], int n, int k) {
        vector<set<int>>g(k);
        vector<int>h(k);
        for(int i = 0;i<n;++i)
        {
            int j = i+1;
            if(j<n)
            {
                int p = 0;
                int q = 0;
                while(p<d[i].size() && q<d[j].size())
                {
                    if(d[i][p]!=d[j][q])
                    {
                        if( g[d[i][p]-'a'].find(d[j][q]-'a')== g[d[i][p]-'a'].end())
                        h[d[j][q]-'a']++;
                        g[d[i][p]-'a'].insert(d[j][q]-'a');
                        break;
                    }
                    ++p,++q;
                }
            }
        }
        string u="";
        queue<int>q;
        for(int i = 0;i<k;++i)
        {
            if(h[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
        //    cout<<i<<" ";
            u+=char('a'+i);
            for(auto c:g[i])
            {
                h[c]--;
                if(h[c]==0)
                q.push(c);
            }
        }
     //   cout<<u<<"\n";
        return u;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
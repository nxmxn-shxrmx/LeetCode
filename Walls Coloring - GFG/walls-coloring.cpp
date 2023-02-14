//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        
        int a =0;
        int b =0;
        int c =0;
        for(auto x:colors)
        {
            int a1 = x[0]+min(c,b);
            int b1 = x[1]+min(a,c);
            int c1 = x[2]+min(a,b);
            a = a1;
            b = b1;
            c = c1;
        }
        
        return min(a,min(b,c));
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends
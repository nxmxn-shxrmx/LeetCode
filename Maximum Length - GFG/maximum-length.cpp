//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        // code here
        int p = a+b+c;
        while(a>0 && b>0 && c>=0)
        {
            if(a==b&&c==b)return p;
            if(c==0  && a==b)return p;
            if(b>a)swap(a,b);
            if(c>a)swap(c,a);
            if(c>b)swap(b,c);
            
            a-=2;
            b-=1;
              //cout<<a<<" "<<b<<" "<<c<<"\n";
            if(b>a)swap(a,b);
            if(c>a)swap(c,a);
            if(c>b)swap(b,c);
    
        }

        if(a==b && c==b)return p;
        if(a<0 ||b<0 || c<0)return -1;
        if(a>2 || b>2 || c>2)return -1;
        return p;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
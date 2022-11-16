//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int v[], int n){
        
        int p =0;
        int e = 0;
        int c = 0;
        for(int i =0;i<n-1;++i)
        {
            p = max(p,i+v[i]);
            if(e==i)
            {
                e = p;
                c++;
                if(v[i]==0 && p==i)
                    return -1;
            }
            p = max(p,i+v[i]);
        }
        if(p>=n-1)
            return c;
        return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
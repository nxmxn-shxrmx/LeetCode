// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int v[], int n){
        
    // Your code here
        long long ans = 0;
        long long m = 0;
        int mz = INT_MIN;
        for(int i = 0;i<n;++i)
        {
            m+=v[i];
            ans = max(m,ans);
            if(m<0)
                m = 0;
            ans =m>ans?m:ans;
            mz = max(mz,v[i]);
        }
        
        if(mz<=0)
        return mz;
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends
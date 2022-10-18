//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> g)
	{
	    vector<int>v;
		for(int k = 0;k<g[0].size();++k)
		{
		    int j = 0;
		    int i = k;
		    while(j<g.size() && i>=0)
		    {
		        v.push_back(g[j][i]);
		        i-=1;
		        j+=1;
		    }
		}
		for(int k = 1;k<g.size();++k)
		{
		    int j = g.size()-1;
		    int i = k;
		    while(i<g.size() && j>=0)
		    {
		        v.push_back(g[i][j]);
		        i+=1;
		        j-=1;
		    }
		}
		return v;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends
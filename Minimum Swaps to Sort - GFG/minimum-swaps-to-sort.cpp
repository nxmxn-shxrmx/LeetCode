//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    map<int,int>m;
	    for(int i = 0;i<nums.size();++i)
	        m[nums[i]]=i;
	    
	    int h = 0;
	    int i = 0;
	    for(auto c:m)
	    {
	        if(c.first!=nums[i])
	        {
	           
	            nums[m[c.first]]=nums[i];
	            m[nums[i]] = m[c.first];
	            nums[i]=c.first;
	            m[c.first]=i;
	            h++;
	        }
	        ++i;
	    }
	    
	    return h;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
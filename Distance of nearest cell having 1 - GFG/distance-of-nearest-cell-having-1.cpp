//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>g)
	{
	    queue<pair<int,int>>q;
	    vector<vector<int>>ans(g.size(),vector<int>(g[0].size(),INT_MAX));
	    for(int i = 0;i<g.size();++i)
	    {
	        for(int j = 0;j<g[0].size();++j)
	        {
	            if(g[i][j]==1)
	                        q.push({i,j});
	        }
	    }
	    int st = 0;
	    int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
	    while(!q.empty())
	    {
	        int sz = q.size();
	        while(sz--)
	        {
	            int x = q.front().first;
	            int y = q.front().second;
	            q.pop();
	            ans[x][y]=min(ans[x][y],st);
	            g[x][y]=1;
	            for(auto c:d)
	            {
	                if(x+c[0]>=0 && x+c[0]<g.size() && y+c[1]>=0 && y+c[1]<g[0].size() && g[x+c[0]][y+c[1]]==0)
	                    q.push({x+c[0],y+c[1]});
	                    
	            }
	       
	        }
	        st++;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
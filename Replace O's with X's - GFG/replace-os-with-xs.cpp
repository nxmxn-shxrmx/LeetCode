//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void dfs(int i,int j,int n,int m ,vector<vector<char>>&v,vector<vector<int>>&b)
{
    int d[4][2]= {{1,0},{-1,0},{0,-1},{0,1}};
    for(auto c:d)
    {
        if(c[0]+i>=0 && c[0]+i<n && c[1]+j>=0 && c[1]+j<m && b[i+c[0]][j+c[1]]==0 && v[i+c[0]][j+c[1]]=='O')
            {
                b[i+c[0]][c[1]+j]=1;
                dfs(i+c[0],j+c[1],n,m,v,b);
            }
    }
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>b(n,vector<int>(m));
        for(int i = 0;i<n;++i)
        {
            if(mat[i][0]=='O')
                if(!b[i][0])
                {
                    b[i][0]=1;
                    dfs(i,0,n,m,mat,b);
                }
            if(mat[i][m-1]=='O')
                if(!b[i][m-1])
                {
                    b[i][m-1]=1;
                    dfs(i,m-1,n,m,mat,b);
                }
        }
           for(int i = 0;i<m;++i)
        {
            if(mat[0][i]=='O')
                if(!b[0][i])
                {
                    b[0][i]=1;
                    dfs(0,i,n,m,mat,b);
                }
            if(mat[n-1][i]=='O')
                if(!b[n-1][i])
                {
                    b[n-1][i]=1;
                    dfs(n-1,i,n,m,mat,b);
                }
        }
      for(int i = 0;i<n;++i)
        {
            for(int j = 0;j<m;++j)
                if(!b[i][j])
                {
                    mat[i][j]='X';
                }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
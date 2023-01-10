class Solution {
public:
     int rec[101][101];
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
       
        for(int i=1;i<=n;++i)
        {
            for(int j = 1;j<=m;++j)
            {
                //  1 2 3
               //   4 5 6
              //    7 8 9
                
                rec[i][j]+=mat[i-1][j-1]+rec[i-1][j]+rec[i][j-1]-rec[i-1][j-1];
            }
        }
        vector<vector<int>>ans(n,vector<int>(m));
        for(int  i=0;i<n;++i)
        {
            for(int j = 0;j<m;++j)
            {
                int r1 = max(0,i-k);
                int c1 = max(0,j-k);
                int r2 = min(n-1,i+k);
                int c2 = min(m-1,j+k);
                
                r1++,c1++,r2++,c2++;
              //  cout<<r1<<" "<<c1<<" "<<r2<<" "<<r2<<"\n";
                ans[i][j]+=rec[r2][c2]-rec[r2][c1-1]-rec[r1-1][c2]+rec[r1-1][c1-1];
            }
        }
        return ans;
    }
};

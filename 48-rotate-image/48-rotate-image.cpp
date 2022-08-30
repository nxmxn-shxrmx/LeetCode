class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        
//         int i =0;
//         while(i<m.size())
//         {
//             int l =i;
//             while(l<m.size())
//             {
//                 swap(m[l][i],m[i][l]);
//                 ++l;
//             }
            
//             ++i;
//         }
//         i = 0;
//         int j = m.size()-1;
//         while(i<j)
//         {
//             for(int k=0;k<m.size();++k)
//             {
//                 swap(m[k][i],m[k][j]);
//             }
//             ++i;
//             --j;
//         }
        int n = m.size();
        
        
        for(int i = 0;i<(n+1)/2;++i)
        {
            for(int j=0;j<n/2;++j)
            {
                int t =  m[ n - 1 - j ][ i ];
                
                 m[ n - 1 - j ][ i ] = m[ n - 1 - i][n - 1 -j];
                
                m[n - 1 - i][ n - 1 - j]=m[ j ][ n - 1 - i];
                
                m[ j ][ n - 1 - i]=m[i][j];
                
                m[i][j]=t;
                        
            }
            
        }
    
    }
};
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int g=0;
        vector<vector<int>>v(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        for(int i= 1;i<=matrix.size();++i)
        {
            for(int j =1;j<=matrix[0].size();++j)
            {
                if(matrix[i-1][j-1]=='0')
                    continue;
            
                v[i][j]+=min(min(v[i-1][j],v[i][j-1]),v[i-1][j-1])+1;
                int h = v[i][j];
                g = max(g,h*h);
            }
    
        }    
        return g;
    }
};
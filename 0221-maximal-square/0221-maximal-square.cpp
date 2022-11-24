class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int g=0;
        vector<vector<pair<int,int>>>v(matrix.size()+1,vector<pair<int,int>>(matrix[0].size()+1,{0,0}));
        for(int i= 1;i<=matrix.size();++i)
        {
            for(int j =1;j<=matrix[0].size();++j)
            {
                if(matrix[i-1][j-1]=='0')
                    continue;
            
                v[i][j].first+=min(min(v[i-1][j].first,v[i][j-1].first),v[i-1][j-1].first)+1;
                v[i][j].second+=min(min(v[i-1][j].second,v[i][j-1].second),v[i-1][j-1].second)+1;

                int h = min(v[i][j].first,v[i][j].second);
            
                g = max(g,h*h);
            }
    
        }    
        return g;
    }
};
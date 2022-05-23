class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>v;
        int n = mat.size();
        int m = mat[0].size();
        for(int i =0;i<n+m-1;++i)
        {
            vector<int>f;
            int x = i<m?0:i-m+1;
            int y = i<m?i:m-1;
            while(x<n && y>=0)
            {
                f.push_back(mat[x][y]);
                x++;
                --y;
            }
            if(i%2==0)
                reverse(f.begin(),f.end());
            
            for(auto c:f)
                v.push_back(c);
        }
        return v;
    }
};
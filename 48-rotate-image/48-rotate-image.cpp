class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        
        int i =0;
        while(i<m.size())
        {
            int l =i;
            while(l<m.size())
            {
                swap(m[l][i],m[i][l]);
                ++l;
            }
            
            ++i;
        }
        i = 0;
        int j = m.size()-1;
        while(i<j)
        {
            for(int k=0;k<m.size();++k)
            {
                swap(m[k][i],m[k][j]);
            }
            ++i;
            --j;
        }
        
    }
};
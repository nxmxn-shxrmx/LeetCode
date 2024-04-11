class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        
        int n = m.size();
        int k = m[0].size();
        int i = 0;
        int j = k-1;
        while(j>=0&&i<n)
        {
        
            
            if(m[i][j]==t)
                return true;
            
            if(m[i][j]>t)
                j--;
            else
                i++;
        }
        return 0;
    }
};
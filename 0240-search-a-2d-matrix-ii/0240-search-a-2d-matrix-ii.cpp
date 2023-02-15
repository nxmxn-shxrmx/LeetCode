class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        
        int n = m.size();
        int k = m[0].size();
        int i = 0;
        int j = k-1;
        while(true)
        {
            if(i==n || i==-1 || j==k || j==-1)
                return false;
            
            if(m[i][j]==t)
                return true;
            
            if(m[i][j]>t)
                j--;
            else
                i++;
        }
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        
    int i=0;
    int j=m[0].size()-1;
    while(j>=0 && i<m.size())
    {
        if(t==m[i][j])
            return true;
        if(t>m[i][j])
            ++i;
    else
        --j;
    }
     
        return false;
    
    }
};
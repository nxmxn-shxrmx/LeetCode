class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        

        
        int rr = matrix.size();
        int i =0;
        int rc  = matrix[0].size()-1;
        
        while(i<rr && rc>=0)
        {
            
            cout<<matrix[i][rc]<<" ";
            if(matrix[i][rc]==target)
                return true;
            else if(matrix[i][rc]>target)
                rc--;
            else
                i++;
    
            
        }
        
        return false;
    }
};
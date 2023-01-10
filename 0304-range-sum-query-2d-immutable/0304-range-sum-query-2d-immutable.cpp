class NumMatrix {
public:
    int rec[201][201];
    NumMatrix(vector<vector<int>>& matrix) {
        memset(rec,0,sizeof(rec));
        for(int i = 1;i<=matrix.size();++i)
        {
            for(int j =1;j<=matrix[0].size();++j)
            {
                rec[i][j]+=matrix[i-1][j-1]+rec[i-1][j]+rec[i][j-1]-rec[i-1][j-1];
            }
        }
       
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++,col1++,row2++,col2++;
        return rec[row2][col2]-rec[row2][col1-1]-rec[row1-1][col2]+rec[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
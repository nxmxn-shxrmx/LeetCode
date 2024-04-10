class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int col1 = 1;
        for(int i = 0;i<m.size();++i)
        {
            for(int j = 0;j<m[0].size();++j)
            {
                if(m[i][j]==0)
                {
                    m[i][0] = 0;
                    
                    if(j!=0)m[0][j]=0;
                    else col1 = 0;
                }
            }
        }
        
        for(int i = 1;i<m.size();++i)
        {
            for(int j = 1;j<m[0].size();++j)
            {
                if(!m[i][0]||!m[0][j])m[i][j]=0;
            }
        }
        if(m[0][0]==0)
        {
            for(int i = 0;i<m[0].size();++i)m[0][i]=0;
        }
        if(col1==0)for(int i = 0;i<m.size();++i)m[i][0]=0;
        
        
            
    }
};
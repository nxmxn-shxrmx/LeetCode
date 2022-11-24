class Solution {
public:
    bool f(int i,int j,vector<vector<char>>&b)
    {
        if(i==b.size() && j==b.size())
            return 1;
        
        if(i==b.size())
            return f(0,j+1,b);
        
        int y = j/3;
        if(y==0)
            y = 1;
        else if(y==1)
            y=4;
        else 
            y = 7;
        int x = i/3;
         if(x==0)
            x = 1;
        else if(x==1)
            x=4;
        else 
            x = 7;
        
        if(b[i][j]!='.')
            return (f(i+1,j,b));
        
        for(int k=1;k<=9;++k)
        {
            char p = '0'+k;
           
            if(p==b[x][y] || p==b[x-1][y] || p==b[x-1][y+1] || p==b[x-1][y-1] || b[x][y-1]==p || p==b[x][y+1] || p==b[x+1][y] || p==b[x+1][y+1] || p==b[x+1][y-1])
                continue;

            int u = 0;
            for(int z = 0;z<9;++z)
            {
                if(b[i][z]==p || b[z][j]==p)
                {
                    u=1;
                    break;
                }
            
            }
            if(u==1)
                continue;
            
            b[i][j]=p;
            if(f(i+1,j,b))
                return 1;
            b[i][j]='.';
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        f(0,0,board);
 
    }
};
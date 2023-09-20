class Solution {
public:
    
    

    int check(int i,int j,vector<vector<int>>&h,vector<vector<int>>&b,int m)
    {
        if(i==h.size()-1 && h[0].size()-1==j)
                return  1;
        int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
       
        if(b[i][j])return 0;
        b[i][j]=1;
        int ans = 0;
        for(auto c:d)
        {
            if(i+c[0]>=0 && i+c[0]<h.size() && j+c[1]>=0 && j+c[1]<h[0].size() && m>=(abs(h[i][j]-h[i+c[0]][j+c[1]])) && !b[i+c[0]][j+c[1]])
            {
             ans |=check(i+c[0],j+c[1],h,b,m);
                if(ans)return 1;
            }
        }

        return 0;    
    }
    int minimumEffortPath(vector<vector<int>>& h) {
        int l = 0;
        int r = 1e6;
        int ans = r;
        while(l<=r)
        {
            int m = (l+r)/2;
            
            vector<vector<int>>b(h.size(),vector<int>(h[0].size()));
            if(check(0,0,h,b,m))
                r = m-1 ,ans = m;
            else l = m+1;
        }
        return ans;
    }
};
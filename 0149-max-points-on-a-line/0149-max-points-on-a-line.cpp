class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int m=0;
        vector<vector<double>>sl(points.size(),vector<double>(points.size()));
        for(int i = 0;i<points.size();++i)
        {
          
            for(int j = i+1;j<points.size();++j)
            {
                double p = points[i][1]-points[j][1];
                double y = points[i][0]-points[j][0];
                if(p==0)
                {
                    sl[i][j]=0;
                    sl[j][i]=0;
                }
                else
                {
                    sl[i][j]=p/y;
                    sl[j][i]=p/y;
                }
            }
        }
        for(int i = 0;i<points.size();++i)
        {
           map<double,int>mi;
            int u =0;
            for(int j = 0;j<points.size();++j)
            {
                if(i!=j)
                {
                    mi[sl[i][j]]++;
                    u= max(u,mi[sl[i][j]]);
                }
            }
            m = max(u,m);
        }
        
        return m+1;
    }
};
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int m=0;
        for(int i = 0;i<points.size();++i)
        {
            map<double,int>mi;
            for(int j = i+1;j<points.size();++j)
            {
                double p = points[i][1]-points[j][1];
                double y = points[i][0]-points[j][0];
                double h = p/y;
                if(y==0)
                    h = INT_MAX;
                mi[h]++;
                m = max(m,mi[h]);
            }
        }

        return m+1;
    }
};
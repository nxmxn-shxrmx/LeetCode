class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& g, int k) {
        while(k--)
        {
            int t = g[0][0];
            int i = 0;
            int j = 0;
            while(i<g.size())
            {
                if(i==g.size()-1 && j==g[0].size()-1)
                {
                    g[0][0]=t;
                    break;
                }
                if(j+1<g[0].size())
                {
        
                    swap(t,g[i][j+1]);
                    ++j;
                    
                }
                else
                {
                    i+=1;
                    j=0;
                    swap(t,g[i][j]);
                }
            }
        }
        return g;
    }

};
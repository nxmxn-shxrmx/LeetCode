class Solution {
public:
    int canCompleteCircuit(vector<int>& g, vector<int>& co) {
        int tol=g[0];
        int c =0;
        int sum =g[0];
        for(int i =1;i<g.size();++i)
        {
            tol=tol-co[i-1]+g[i];
            sum-=co[i-1];
            if(sum<0)
            {
                c = i;
                sum = g[i];
            }
            else
            sum+=g[i];
        }
        tol-=co.back();
        if(tol<0)
            return -1;
        return c;
    }
};
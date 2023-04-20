class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        pair<int,int>a;
        pair<int,int>b;
        a.first = 0;
        a.second = -1;
        b.first = 0;
        b.second = -1;
        for(auto x:grid)
        {
            pair<int,int>c;
            c.first = INT_MAX;
            c.second=-1;
            pair<int,int>d;
            d.second=-1;
            d.first = INT_MAX;
            for(int i = 0;i<x.size();++i)
            {
                if(a.second!=i)
                {
                    if(a.first+x[i]<=c.first)
                    {
                        swap(d,c);
                        c.first = a.first+x[i];
                        c.second=i;
                    }
                    else if(a.first+x[i]<d.first)
                    {
                        d.first = a.first+x[i];
                        d.second = i;
                    }
                }
                else
                {
                    if(b.first+x[i]<=c.first)
                    {
                        swap(d,c);
                        c.first = b.first+x[i];
                        c.second=i;
                    }
                    else if(b.first+x[i]<d.first)
                    {
                        d.first = b.first+x[i];
                        d.second = i;
                    
                    }
                }
             
             //   cout<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second<<"\n";
            }
               a= c;
                b = d;
        }
             return min(a.first,b.first);
    }
    
};
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int c = 0;
        int u = v[0]+v[1]-1;
        int p;
        if(v[0]>v[1])
        {
            c = 0;
            p = v[0];
        }
        else
        {
            c=1;
            p = v[1];
        }
        for(int i = 2;i<v.size();++i)
        {
            u = max(u,v[i]+p+c-i);
            if(v[i]>=(p+c-i))
            {
                c = i;
                p = v[i];
            }
    
        }
        return u;
    }
};

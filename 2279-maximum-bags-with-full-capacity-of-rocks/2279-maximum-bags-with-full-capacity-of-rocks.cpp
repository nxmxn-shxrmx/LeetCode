class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int a) {
        vector<int>v(capacity.size());
        for(int i = 0;i<capacity.size();++i)
            v[i] = capacity[i]-rocks[i];
        sort(v.begin(),v.end());
        int u = 0;
        for(auto c:v)
        {
            if(a>=c)
            {
                a-=c;
                u++;
            }
            else
                break;
        }
        return u;
    }
};
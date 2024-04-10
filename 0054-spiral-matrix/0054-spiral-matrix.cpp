class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int>v;
        int t = 0;
        int l = 0;
        int ri = m[0].size()-1;
        int bo = m.size()-1;
        int ct = m.size()*m[0].size();
        ct = 1;
        while(t<=bo&&l<=ri)
        {
            for(int i = l;i<=ri;++i)
            {
                v.push_back(m[t][i]);
            }
            t++;
            for(int i =t;i<=bo;++i)
            {
                v.push_back(m[i][ri]);
            }
            ri--;
            if(t<=bo)
            {
                for(int i = ri;i>=l;--i)
                  v.push_back(m[bo][i]);
                bo--;
            }
        
            if(l<=ri)
            {
                for(int i= bo;i>=t;--i)
                v.push_back(m[i][l]);
                l++;
            }
            
        }
        return v;
    }
};
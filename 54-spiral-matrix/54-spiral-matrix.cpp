class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int i1=0,i2=m.size()-1;
        int j1=0,j2=m[0].size()-1;
       int cou = m.size()*(m[0].size());
        int x = cou;
        vector<int>v;
        while(cou)
        {
            for(int i=j1;i<=j2;++i)
            {
                cou--;
                v.push_back(m[i1][i]);
                if(v.size()==x)
                    return v;
            }
            i1++;
            for(int i = i1;i<=i2;++i)
            {
                cou--;
                v.push_back(m[i][j2]);
                 if(v.size()==x)
                    return v;
            }
            j2--;
            for(int i = j2;i>=j1;--i)
            {
                cou--;
                v.push_back(m[i2][i]);
                 if(v.size()==x)
                    return v;
                
            }
            i2--;
            for(int i=i2;i>=i1;--i)
            {
                       cou--;
                v.push_back(m[i][j1]);
                 if(v.size()==x)
                    return v;
            }
            j1++;
        }
     
        return v;
    }
};

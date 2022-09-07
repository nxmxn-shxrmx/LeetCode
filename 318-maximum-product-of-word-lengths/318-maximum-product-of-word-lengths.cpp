class Solution {
public:
    int maxProduct(vector<string>& w) {
       vector<vector<int>>v(w.size(),vector<int>(26));
        for(int i =0;i<w.size();++i)
        {
            for(auto c:w[i])
                v[i][c-'a']++;
        }
        
        long long y =0;
        for(int i =0;i<w.size();++i)
        {
            for(int j =i+1;j<w.size();++j)
            {
                bool l = 0;
                for(int k =0;k<26;++k)
                {
                    if(v[i][k] && v[j][k])
                    {
                        l=1;
                        break;
                    }
                }
                if(!l)
                {
                    long long u = w[i].size()*w[j].size();
                    y =max(u,y);
                }
            }
        }
        return y;
    }
};
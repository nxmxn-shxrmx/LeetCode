class Solution {
public:
    int maxProduct(vector<string>& w) {
       vector<int>v(w.size());
        for(int i =0;i<w.size();++i)
        {
            for(auto c:w[i])
                v[i] =v[i]| (1<<(c-'a'));
        }
          
        
        long long y =0;
        for(int i =0;i<w.size();++i)
        {
            for(int j =i+1;j<w.size();++j)
            {
                
                if((v[i]&v[j])==0)
                {
                    long long u = w[i].size()*w[j].size();
                    y =max(u,y);
                }
            }
        }
        return y;
    }
};
    
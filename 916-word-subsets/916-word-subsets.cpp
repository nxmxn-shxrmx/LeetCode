class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        
        vector<string>v;
        map<char,int>m;
        for(auto c:w2)
        {
            map<char,int>d;
            
            for(auto z:c)
                d[z]++;    
    
            for(auto z:d)
            {
                m[z.first]=max(m[z.first],d[z.first]);   
            }
        }
    
        for(auto c:w1)
        {
            map<char,int>g;
            for(auto x:c)
                g[x]++;   
        
            bool k =0;
            for(auto x:m)
            {
                if(m[x.first]>g[x.first])
                {
                    k =1;
                    break;
                }
            }
            if(!k)
                v.push_back(c);
            
        }
        
        return v;
    }
};
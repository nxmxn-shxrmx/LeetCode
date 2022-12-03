class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>>v(75,{0,'a'});
        
        for(auto c:s)
        {
            v[c-'0'].first+=1;
            v[c-'0'].second=c;
        }
        string t = "";
        sort(v.rbegin(),v.rend());
        for(auto c:v)
        {
            int x =c.first; 
            while(x--)
            {
                t+=c.second;
            }
        }
        return t;
    }
};
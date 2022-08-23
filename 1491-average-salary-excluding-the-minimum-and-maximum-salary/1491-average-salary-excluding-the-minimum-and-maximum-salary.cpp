class Solution {
public:
    double average(vector<int>& s) {
    
        int ma=INT_MIN,mi=INT_MAX;
        double h = 0;
        for(auto c:s)
        {
            ma = max(c,ma);
            mi=min(c,mi);
            h+=c;
        }
        h-=ma;
        h-=mi;
        
        return h/(s.size()-2)*1.0;
        
    }
    
};
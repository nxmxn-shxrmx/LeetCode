class Solution {
public:
    double average(vector<int>& s) {
    
        int ma=*max_element(s.begin(),s.end());
        int mi=*min_element(s.begin(),s.end());
        int h =0;
       double j= accumulate(s.begin(),s.end(),h);
    
        j-=ma;
        j-=mi;
        
        return j/(s.size()-2);
        
    }
    
};
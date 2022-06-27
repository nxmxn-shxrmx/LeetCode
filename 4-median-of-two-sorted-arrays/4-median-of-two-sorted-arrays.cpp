class Solution {
public:
    double findMedianSortedArrays(vector<int>& n, vector<int>& m) {
        multiset<int>s(n.begin(),n.end());
        s.insert(m.begin(),m.end());
        vector<int>v(s.begin(),s.end());
    
        if(v.size()%2)
            return v[v.size()/2];
        
        double h = v[v.size()/2]+v[v.size()/2-1];
        return h/2.000;
    }
};
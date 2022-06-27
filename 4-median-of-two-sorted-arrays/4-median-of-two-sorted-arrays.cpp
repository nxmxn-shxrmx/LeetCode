class Solution {
public:
    double findMedianSortedArrays(vector<int>& n, vector<int>& m) {
        
        vector<int>v;
        
        int i = 0;
        int j = 0;
        
        while(i<n.size() && j<m.size())
        {
            if(n[i]>m[j])
                v.push_back(m[j++]);
            else
                v.push_back(n[i++]);
        }
        while(i<n.size())
            v.push_back(n[i++]);
        while(j<m.size())
            v.push_back(m[j++]);
        
        if(v.size()%2)
            return v[(v.size())/2];
        
        double h = (v[v.size()/2]+v[(v.size())/2 - 1]);
//        cout<<v[v.size()/2]<<" "<<v[v.size()/2 -1]<<"\n";
        return h/2.000;
    }
};
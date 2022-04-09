class Solution {
public:
    vector<int>m;
    int sub(vector<int>&n,int i)
    {
        if(i>=n.size())
            return 0;
        if(m[i]>=0)
            return m[i];
        int r =  max(sub(n,i+2)+n[i],sub(n,i+1));
        m[i]= r;
        return r;
    }
    int rob(vector<int>& n) {
        if(n.size()==1)
            return n[0];
        
        m = vector<int>(n.size()+1,-1);
        int u =sub(n,0);
        for(auto c:m)
            cout<<c<<" ";
        cout<<"\n";
        return u;
    }
};
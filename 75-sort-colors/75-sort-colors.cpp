class Solution {
public:
    void mer(vector<int>&v,int l,int m,int r)
    {
        int i = l;
        int j = m+1;
        vector<int>me;
        while(i<=m && j<=r)
        {
            if(v[i]>=v[j])
            {
                me.push_back(v[j]);
                ++j;
            }
            
            else
            {
                me.push_back(v[i]);
                ++i;
            }
                
        }
        while(i<=m)
        {
            me.push_back(v[i]);
            ++i;
        }
         while(j<=r)
        {
            me.push_back(v[j]);
            ++j;
        }
        for(int i = l;i<=r;++i)
            v[i]=me[i-l];
            
        return;
    }
    void sort(vector<int>&v,int l,int r)
    {
        if(l<r)
        {
            int m = (l+r)/2;
            sort(v,l,m);
            sort(v,m+1,r);
            mer(v,l,m,r);
        }
        return;
    }
    void sortColors(vector<int>& nums) {
     
        sort(nums,0,nums.size()-1);
    
    }
};
class Solution {
public:
    int c = 0;
    void merge(vector<int>&v,int l,int m,int r)
    {
        
        int i=l;
        int j=m+1;
        
        vector<int>b;
        int k = m+1;
        while(i<=m && j<=r)
        {
            long long u= v[j];
            u*=2;
            
            if(v[i]<=u)
                ++i;
            
            else
            {
                 c+=(m-i+1);
                ++j;
            }
        }
        i = l;
         j = m+1;
         while(i<=m && j<=r)
        {
            if(v[i]<v[j])
            b.push_back(v[i++]);
            
            else
            {
                 b.push_back(v[j++]);
                
            }
        }
        while(i<=m)
        {
            b.push_back(v[i]);
            //c+=(j-m-1);
            ++i;
        }
        while(j<=r)
        {
            b.push_back(v[j]);
            ++j;
        }
        for(int i =l;i<=r;++i)
        {
            v[i] = b[i-l];
        }
      
    }
    
    void div(vector<int>& v,int l,int r)
    {
        if(l<r)
        {
            int m = (l+r)/2;
            div(v,l,m);
            div(v,m+1,r);
            merge(v,l,m,r);
        }
        return;
    }
    int reversePairs(vector<int>& nums) {
        
        div(nums,0,nums.size()-1);
   //     cout<<"\n";
    
     return c;
    }
};
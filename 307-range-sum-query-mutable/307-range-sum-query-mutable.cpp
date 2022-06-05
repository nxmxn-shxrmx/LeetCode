class NumArray {
public:
    vector<long long>v;
    vector<int>f;
    NumArray(vector<int>& nums) {
        
        v = vector<long long>(nums.size()+1,0);
        f = vector<int>(nums.size()+1,0);
        for(int i = 0;i<nums.size();++i)
        {   
            update(i,nums[i]);
            f[i+1]=nums[i];
        }
        
    }
    
    void update(int in, int val) {
        
        in+=1;
        int i = in;
        while(in<v.size())
        {
            v[in]+=(val-f[i]);
            in+=(in&(-in));
        }
        f[i]=val;
    }
    
    int sumRange(int l, int r) {
        
        long long s = 0;
        ++r;

        while(r>=1)
        {
          // cout<<r<<" ";
            s+=v[r];
            r-=(r&(-r));
            //cout<<r<<" r\n";
        }
        while(l>=1)
        {
           // cout<<l<<" ";
            s-=v[l];
            l-=(l&(-l));
         //   cout<<l<<" l\n";
        }
        return s;
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
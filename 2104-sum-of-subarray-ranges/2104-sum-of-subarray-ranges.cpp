class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int>l,r;
        l.push(0);
        r.push(nums.size()-1);
        vector<int>len(nums.size()),rin(nums.size());
        long long ans =0;
        rin[nums.size()-1]=nums.size()-1;
        for(int i = 1,j=nums.size()-2;i<nums.size();--j,++i)
        {
            
            while(!l.empty()&&nums[l.top()]>=nums[i])
                l.pop();
            while(!r.empty()&&nums[r.top()]>nums[j])
                r.pop();
            if(l.empty())len[i] = 0;
            else len[i] = l.top()+1;
            
            if(r.empty())rin[j]=nums.size()-1;
            else rin[j] = r.top()-1;
            
            l.push(i);
            r.push(j);
        }
        l=stack<int>();
        r=stack<int>();
        l.push(0);
        r.push(nums.size()-1);
        vector<int>lem(nums.size()),rim(nums.size());
        rim[nums.size()-1]=nums.size()-1;
        for(int i = 1,j=nums.size()-2;i<nums.size();--j,++i)
        {
            
            while(!l.empty()&&nums[l.top()]<=nums[i])
                l.pop();
            while(!r.empty()&&nums[r.top()]<nums[j])
                r.pop();
            if(l.empty())lem[i] = 0;
            else lem[i] = l.top()+1;
            
            if(r.empty())rim[j]=nums.size()-1;
            else rim[j] = r.top()-1;
            
            l.push(i);
            r.push(j);
        }
       
        for(int i = 0;i<nums.size();++i)
        {
            
            long long mn = (i-len[i]+1)*(rin[i]-i+1);
            long long mx = (i-lem[i]+1)*(rim[i]-i+1);
         //   cout<<mn<<" "<<mx<<"\n";
            ans +=(mx-mn)*nums[i];
            
        }
        return ans;
    }
};
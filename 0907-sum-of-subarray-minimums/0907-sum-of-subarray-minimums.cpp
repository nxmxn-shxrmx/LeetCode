class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int>l(arr.size()),r(arr.size());
        stack<int>s;
        s.push(0);
        for(int i= 1;i<arr.size();++i)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
                s.pop();
            if(s.empty())l[i]=0;
            else l[i] = s.top()+1;
            
            s.push(i);
        }
        s = stack<int>();
        s.push(arr.size()-1);
        r[arr.size()-1]=arr.size()-1; 
        for(int i = arr.size()-2;i>=0;--i)
        {
            while(!s.empty() && arr[s.top()]>arr[i])
                s.pop();
            if(s.empty())r[i] = arr.size()-1;
            else r[i] = s.top()-1;
            
            s.push(i);
        }
        int mod = 1e9+7;
        int ans = 0;
        for(int i =0;i<arr.size();++i)
        {
            long long u = (i-l[i]+1)*(r[i]-i+1);
            long long p =arr[i];
           // cout<<i<<" "<<l[i]<<" "<<r[i]<<"\n";
            u = u*p%mod;
          //  cout<<u<<"\n";
            ans = (ans%mod+u%mod)%mod; 
        }
        return ans%mod;
    }
};
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long>ans(n);
        ans[0]=1;
        sort(primes.begin(),primes.end());
        vector<int>v(primes.size());
        for(int i =1;i<n;++i)
        {
            int u = 0;
            long long p = INT_MAX;
            for(int j = 0;j<primes.size();++j)
                if(p>ans[v[j]]*primes[j])
                    p = ans[v[j]]*primes[j],u = j;
            v[u]++;
            if(ans[i-1]==p)
                i--;
            else
            ans[i]=p;
          
            
        }
      
        return ans[n-1];
    }
};
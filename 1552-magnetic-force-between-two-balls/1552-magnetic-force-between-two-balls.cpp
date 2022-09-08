class Solution {
public:
    #define ll long long
   bool isValid(vector<int> v,int m,int k){
       
        int balls = 1;
       int u =0;
       for(int i=1;i<v.size();i++){
           if((v[i]-v[u])>=m) balls++,u=i;
              if(balls>=k)
        return true;
       }
       if(balls>=k)
        return true;
  return false;
   }
    
    int maxDistance(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        ll r = v[v.size()-1]-v[0];
        ll l =1;
        ll ans =0;
        while(l<=r)
        {
            ll m = (l+r)/2;
            if(isValid(v,m,k))
            {
                l = m+1;
                ans = m;
            }
            else
                r = m-1;
        }
        return ans;
    }
};